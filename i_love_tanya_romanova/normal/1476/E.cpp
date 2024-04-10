/*
See the white light
The light within
Be your own disciple
Fan the sparks of will
For all of us waiting
Our kingdom will come
Rays of power shining
Rays of magic fall
On the golden voice that speaks within us all
For all of us waiting
Your kingdom will come
Kingdom Come

Feel the white light
The light within
Yea it burns a fire that drives a man to win
For all of us waiting
Your kingdom will come

Kingdom Come

Words of power
Calling to us all
Holding us together while other kingdoms fall
No longer waiting
Our kingdom has come

Kingdom Come

Kingdom coming
Another kingdom falls
The rightful are waiting
But all are not rightful
Wait and receive the weight of the fall

Kingdom Come
*/

#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <math.h>
#include <memory.h>
#include <stdio.h>

#include <algorithm>
#include <complex>
#include <ctime>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define left asdgashgrketwjklrej
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd
#define prev asdgSHJsfgsdfhdsh
#define hash asdgasdgasdgdfrywewery

#define eps 1e-12
#define M_PI 3.141592653589793
#define bsize 1024

#define ldouble long double
using namespace std;

const long long bs = 1000000007;

const long long N = 1100031;

int n,m,k;
string pat[N];
int pat_value[N];
vector<int> val_to_id[N];

int get_val(char c){
	if (c=='_')
		return 0;
	return c-'a'+1;
}

int eval_pat(string st){
	int res=0;
	for (int i=0;i<st.size();i++){
		res=res*30+get_val(st[i]);
	}
	return res;
}

string inp[N];
int lb[N];
vector<int> order;
vector<int> special[N];
int earliest[N];

int PAT_CNT=30*30*30*30;
int FI[N];

int string_to_pat(string s,int mask){
	int ret=0;
	for (int i=0;i<s.size();i++){
		ret=ret*30;
		if (mask&(1<<i))
			ret+=0;
		else
			ret+=get_val(s[i]);
	}
	return ret;
}

int first_in[N];
vector<int> ans;
int used[N];
vector<int> g[N],gr[N];
int have_cycle;

void dfs(int v){
	if (have_cycle)
		return;
	used[v]=1;
	for (int i=0;i<g[v].size();i++){
		int to=g[v][i];
		if (used[to]==2)
			continue;
		if (used[to]==1){
			have_cycle=1;
		}
		dfs(to);
	}
	used[v]=2;
	order.push_back(v);
}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n>>m>>k;

    for (int i=1;i<=n;i++){
    	cin>>pat[i];
    	pat_value[i]=eval_pat(pat[i]);
    	val_to_id[pat_value[i]].push_back(i);
    }

    for (int i=0;i<PAT_CNT;i++){
    	first_in[i]=-1;
    }

    for (int i=1;i<=m;i++){
    	cin>>inp[i];
    	cin>>lb[i];

    	if (first_in[pat_value[lb[i]]]!=-1&&first_in[pat_value[lb[i]]]!=lb[i])
    	{
    		cout<<"NO"<<endl;
    		return 0;
    	}

    	first_in[pat_value[lb[i]]]=lb[i];

    	int makes_sense=0;
    	for (int mask=0;mask<(1<<k);mask++){
    		int here=string_to_pat(inp[i],mask);
    		if (here==pat_value[lb[i]])
    			makes_sense=1;
    		else
    		{
    			g[pat_value[lb[i]]].push_back(here);
    			gr[here].push_back(pat_value[lb[i]]);
    		}
    	}

    	if (!makes_sense){
    		cout<<"NO"<<endl;
    		return 0;
    	}

    }

    for (int i=0;i<PAT_CNT;i++){
    	if (used[i]==0){
    		dfs(i);
    	}
    }

    if (have_cycle){
    	cout<<"NO"<<endl;
    	return 0;
    }

    reverse(order.begin(),order.end());
    for (int i=0;i<order.size();i++){
    	int id=order[i];
    	for (int j=0;j<val_to_id[id].size();j++){
    		int here=val_to_id[id][j];
    		if (here==first_in[id])
    			ans.push_back(here);
    	}
    	for (int j=0;j<val_to_id[id].size();j++){
    		int here=val_to_id[id][j];
    		if (here!=first_in[id])
    			ans.push_back(here);
    	}
    }


    cout<<"YES"<<endl;
    for (int i=0;i<ans.size();i++){
    	if (i)
    		cout<<" ";
    	cout<<ans[i];
    }
    cout<<endl;

    //cin.get(); cin.get();
    return 0;
}