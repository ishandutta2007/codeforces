/*
I breach your life
Indoctrinate
Police your thoughts
Ask why I hate
I lose control
When I see your face
Abusing power
I infiltrate
Continue lies
Then masturbate
I walk the line
I'll do no time
I hate your church
I'll burn your state
A bleeding heart
A seal of fate
There is no crime
Within my mind
I'll sell your life and preach your death
A wicked plan born of contempt
Bleeding my ideology through pain

Audacious plans
I calculate
A new world view
I'll re-instate
Don't cross my path
Or I'll see you burn
You'll meet your end
Find death alone
No grave to mark
The seds you've sown
You've pushed too far
My secrets I defend
I'll sell your life and preach your death
A wicked plan born of contempt
Bleeding my ideology through pain

Demonize what is feared profane architect
Skull and bones through the mind
Barbaric thoughts of old
Celebrate all unknown
At last the dead await
The die is cast for the meek
Inherit endless dead time
Smell the victims are near
consume the catalyst
Hunting masses for game
implanting septic thoughts
Reaping terror through words while
armed behind your back
Pseudo leaders betray
enslaving all of mankind
Cast out the Demi God
Dethrone the demagogue
Cast out the church God
I command your life
And I don't care
Let bullets rain
From everywhere
No suicide
Will save you from yourself
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

const int N = 500031;

int n;
vector<int> g[N];

int used[N];
int subsize[N];
vector<pair<int,int> > sons[N];
int dep[N];
int max_dep[N];

void dfs(int v){
	used[v]=1;
	max_dep[v]=dep[v];
	subsize[v]=1;
	for (int i=0;i<g[v].size();i++){
		int to=g[v][i];
		if (used[to])
			continue;
		dep[to]=dep[v]+1;
		dfs(to);
		subsize[v]+=subsize[to];
		max_dep[v]=max(max_dep[v],max_dep[to]);
		sons[v].push_back(make_pair(max_dep[to],to));
	}
	sort(sons[v].begin(),sons[v].end());
}

int maps[N];
vector<int> ans_moves;

void solve(int cur,int l,int r){
	maps[l]=cur;
	int ttl_used=1;
	for (int i=0;i<sons[cur].size();i++){
		int vertex_here=sons[cur][i].second;
		int need_here=subsize[vertex_here];
		solve(vertex_here,l+ttl_used,l+ttl_used+need_here-1);
		ttl_used+=need_here;
		if (i+1<sons[cur].size())
			{
				for (int j=0;j<max_dep[vertex_here]-dep[cur];j++){
					ans_moves.push_back(l+ttl_used);
				}
			}
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
    for (int i=1;i<n;i++){
    	int par;
    	cin>>par;
    	g[par].push_back(i);
    }

    dfs(0);

    solve(0,0,n-1);

    for (int i=0;i<n;i++){
    	if (i)
    		cout<<" ";
    	cout<<maps[i];
    }
    cout<<endl;

    cout<<ans_moves.size()<<endl;

    for (int i=0;i<ans_moves.size();i++){
    	if (i)
    		cout<<" ";
    	cout<<maps[ans_moves[i]];
    }
    cout<<endl;


//    cin.get(); cin.get();
    return 0;
}