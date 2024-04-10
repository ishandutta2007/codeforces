/*
I take one step forward and two steps back
It's always been like that, it shouldn't be like that
I'm trying to overcome myself
Trying to work around this hell
Two steps forward and three steps back
Why is life like that? Why am I like that?
I'm trying to understand myself
Trying to fight through this hell

Why can't I see this clearly? (See this clearly)
Why can't I?

Hey hey you, are you living the dream?
If you've seen what I've seen, nothing is clean
Hey hey you, while I'm rolling the dice
I'm paying the price, I've been walking on ice
Hey hey you, just get outta my way
At the end of the day, you've got nothing to say
Hey hey you, see the look in my eyes
Will the sun ever rise, will the sun ever rise?

Will the sun ever rise again?

All the days gone by and I can't get 'em back
What was my name now, what is my name now?
Trying to rise above myself
Trying to look beyond this hell
Seems like I got way off track
No one ever found me, no one unbound me
They wonder why I hate myself
Surrounded by a living hell

Why can't I see this clearly? (See this clearly)
Why can't I?

Hey hey you, are you living the dream?
If you've seen what I've seen, nothing is clean
Hey hey you, while I'm rolling the dice
I'm paying the price, I've been walking on ice
Hey hey you, just get outta my way
At the end of the day, you've got nothing to say
Hey hey you, see the look in my eyes
Will the sun ever rise, will the sun ever rise?

Will the sun ever rise?
Will the sun ever rise?
Will the sun ever rise, will the sun ever rise?
Will the sun ever rise?

Hey hey you, are you living the dream?
If you've seen what I've seen, nothing is clean
Hey hey you, while I'm rolling the dice
I've been paying the price, I've been walking on ice
Hey hey you, just get outta my way
At the end of the day, you've got nothing to say
Hey hey you, see the look in my eyes
Will the sun ever rise, will the sun ever rise?

Will the sun ever rise?
Will the sun ever rise?
Will the sun ever rise?
No!
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
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd
#define prev asdgSHJsfgsdfhdsh

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 600031;

int n,m,s;
vector<int> g[N];
vector<int> urder;
int used[N];
int C;
vector<int> gr[N];
vector<int> order;

void dfs(int v){
	used[v]=1;
	for (int i=0;i<g[v].size();i++){
		int to=g[v][i];
		if (used[to])
			continue;
		dfs(to);
	}
	order.push_back(v);
}

void rdfs(int v){
	used[v]=C;
	for (int i=0;i<gr[v].size();i++){
		int to=gr[v][i];
		if (used[to])
			continue;
		rdfs(to);
	}
}

int indeg[N];

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n>>m>>s;

	for (int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		gr[b].push_back(a);
	}

	for (int i=1;i<=n;i++){
		if (used[i])
			continue;
		dfs(i);
	}

	for (int i=1;i<=n;i++){
		used[i]=0;
	}

	reverse(order.begin(),order.end());

	for (int i=0;i<order.size();i++){
		int v=order[i];
		if (used[v])
			continue;
		++C;
		rdfs(v);
	}

	/*for (int i=1;i<=n;i++){
		cout<<used[i]<<" ";
	}
	cout<<endl;

*/
	for (int i=1;i<=n;i++){
		for (int j=0;j<g[i].size();j++){
			int a=i;
			int b=g[i][j];
			a=used[a];
			b=used[b];
			if (a==b)
				continue;
			indeg[b]++;
	//		cout<<a<<"$"<<b<<" "<<indeg[b]<<endl;
		}
	}

	s=used[s];
	indeg[s]=1;

	int ans=0;

	for (int i=1;i<=C;i++){
		if (indeg[i]==0)
			++ans;
	}

	cout<<ans<<endl;

//	cin.get(); cin.get();
	return 0;
}