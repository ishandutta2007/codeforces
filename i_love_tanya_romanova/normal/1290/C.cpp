/*
Cutting through confusion,
Takes you far away.
Confusing an illusion,
With thoughts that go astray.

In a world gone mad and thriving in the boundaries of your brain,
Imprisoned in a world created soley for the purpose of a crunch.

What ya see and what ya feel,
Are nothing nothing real.
A visionary climax!
An imagery so clear.
Losing touch or reason,
Both quickly slip away.
Imprisoned in a world created soley for the purpose of a...

Save me from this mad gone world.
Save me from myself.
Save me from this mad gone world!!!
I need help.
Save me from this mad gone world.
Save me from decisions.
Save me from this mad gone world!!!
And indecision!!!

One million minutes...
One million nights.
One million dreams I've had!
And a million fights.
Livin' in a mad gone world,
Livin' blind.
Livin' with this worldly madness,
Just a state of mind.
Just a state of mind.

Mad! Mad gone world!
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

const int N = 300031;

int n,k;
string st;
int w[N];
int enforced[N];
int sz[N][2];
vector<int> entries[N];
int answ[N];
int ans;
int clr[N];
vector<int> comp[N];

int get (int x){
	if (x==w[x])
		return x;
	return w[x]=get(w[x]);
}

void subtract(int id){
	id=get(id);
	if (enforced[id]==-1)
		ans-=min(sz[id][0],sz[id][1]);
	if (enforced[id]==0)
		ans-=sz[id][1];
	if (enforced[id]==1)
		ans-=sz[id][0];
}

void add_back(int id){
	id=get(id);
	if (enforced[id]==-1)
		ans+=min(sz[id][0],sz[id][1]);
	if (enforced[id]==0)
		ans+=sz[id][1];
	if (enforced[id]==1)
		ans+=sz[id][0];
}

void run_merge(int a,int b,char c){
	bool are_same=(c=='1');
	if (comp[get(a)].size()>comp[get(b)].size())
		swap(a,b);
	// now merge a to b
	int c1=get(a);
	int c2=get(b);

	if (enforced[c1]==1){
		for (int i=0;i<comp[c1].size();i++){
			int id=comp[c1][i];
			clr[id]^=1;
		}
		enforced[c1]=0;
	}

	bool should_flip=0;
	if (are_same==1&&(clr[a]!=clr[b]))
		should_flip=1;
	if (are_same==0&&(clr[a]==clr[b]))
		should_flip=1;

//	cout<<a<<" "<<b<<" "<<are_same<<endl;

	for (int i=0;i<comp[c1].size();i++){
		int id=comp[c1][i];
		comp[c2].push_back(id);
		if (should_flip)
			clr[id]^=1;
		sz[c2][clr[id]]++;
	}

	if (enforced[c1]!=-1&&enforced[c2]==-1){
		enforced[c2]=should_flip;
	}

	w[c1]=c2;
	//cout<<c1<<" "<<c2<<" "<<sz[c2][0]<<" "<<sz[c2][1]<<" "<<enforced[c2]<<endl;

}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n>>k;
    cin>>st;
    for (int i=1;i<=k;i++){
    	w[i]=i;
    	enforced[i]=-1;
    	sz[i][0]=1;
    	sz[i][1]=0;
    	comp[i].push_back(i);
    }

    for (int i=1;i<=k;i++)
    {
    	int sz;
    	cin>>sz;
    	for (int j=0;j<sz;j++){
    		int id;
    		cin>>id;
    		entries[id].push_back(i);
    	}
    }

    for (int i=1;i<=n;i++){
    	if (entries[i].size()==0){
    		answ[i]=ans;
    		continue;
    	}
    	if (entries[i].size()==1){
    		int id=entries[i][0];
    		int should_be;
    		if (st[i-1]=='0')
    			should_be=1;
    		 else
    			should_be=0;
    		subtract(id);
    		//cout<<id<<"@@@"<<should_be<<" "<<get(id)<<endl;
    		if (should_be!=clr[id])
    			enforced[get(id)]=1;
    		else
    			enforced[get(id)]=0;
    		add_back(id);
    		answ[i]=ans;
    		continue;
    	}
    	// size=2 now
    	int id1=entries[i][0];
    	int id2=entries[i][1];
    	if (get(id1)==get(id2)) // same set
    	{
    		answ[i]=ans;
    		continue;
    	}
    	// otherwise merge
    	subtract(id1);
    	subtract(id2);
    	run_merge(id1,id2,st[i-1]);
    	add_back(id1);
    	answ[i]=ans;
    }

    for (int i=1;i<=st.size();i++){
    	cout<<answ[i]<<"\n";
    }

    //    cin.get(); cin.get();
    return 0;
}