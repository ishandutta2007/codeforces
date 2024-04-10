/*
And so we begin with another sun
The earth's enslaved with hypocrites
They lay their heads to rest at night
Say a little prayer and all is right

Christ it's nothing personal
You've got to see
They twist and turn your words
For their own needs
They're brainwashed puppets
The almighty crutch
Cowards of reality
And their dying love

Living life in total lies
Judging others
Believe that I say or burn in hell
Bow down your head
You won't feel so bad
Do as I say or burn in hell

Close your eyes, look deep inside
Master of the ignorant
Master of the lies
Judgment day is close at hand
Generate that blasphemy
Master of the damned

Lies

Now behind your reflection
Lies the one who knows the truth
Your conscience will condemn you
On judgment day you'll lose

It seems very odd to me
How you sin and feel so free
And all you have to do is say
Forgive me... I believe

Lies, foolish lies
Behind your brainwashed eyes
Lies, foolish lies
Behind your brainwashed eyes

Judge me not my shallow friend
Lest ye be judged yourself
You abuse the words you preach
You mold them for yourself
Brainwashed hypocrisy
Justifies the life you lead
Forgive me father I have sinned
Lay my head to rest again

Living life in total lies
Judging others
Believe what I say or burn in hell
Trust in me, say yes I believe
Do it now or burn in hell
*/

#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>

#include <memory.h>
#include <assert.h>

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

#define eps 1e-9
#define M_PI 3.141592653589793
#define bsize 1024

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 510031;

int n,p[N],c[N];
int root;
vector<int> g[N];
int crap;
int ans[N];
vector<pair<int,int> > sons[N];

void dfs(int v){

	for (int i=0;i<g[v].size();i++){
		int to=g[v][i];
		dfs(to);
		sons[v].push_back(make_pair(ans[to],to));
		for (int j=0;j<sons[to].size();j++){
			sons[v].push_back(sons[to][j]);
		}
	}

	for (int i=0;i<sons[v].size();i++){
		int id=sons[v][i].second;
		sons[v][i].first=ans[id];
	}

	sort(sons[v].begin(),sons[v].end());
	if (sons[v].size()<c[v]){
		crap=1;
		return;
	}
	if (c[v]==0)
		ans[v]=1;
	else
		ans[v]=sons[v][c[v]-1].first+1;

	int thold=ans[v]+1;
	for (int i=c[v];i<sons[v].size();i++){
		int id=sons[v][i].second;
		ans[id]=max(ans[id],thold);
		thold=ans[id]+1;
		sons[v][i].first=ans[id];
	}
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    cin>>n;
    for (int i=1;i<=n;i++){
    	cin>>p[i]>>c[i];
    	if (p[i]==0){
    		root=i;
    	}
    	else
    	{
    		g[p[i]].push_back(i);
    	}
    }

    dfs(root);

    if (crap){
    	cout<<"NO"<<endl;
    }
    else
    {
    	cout<<"YES"<<endl;
    	for (int i=1;i<=n;i++){
    		ans[i]+=1000000;
    	}
    	for (int i=1;i<=n;i++){
    		if (i>1)
    			cout<<" ";
    		cout<<ans[i];
    	}
    	cout<<endl;
    }

    //    cin.get(); cin.get();
    return 0;
}