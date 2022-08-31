/*
Here comes the biggest asshole that the whole world's ever seen
Watch as things turn to something I never, I never meant to be
Call it a side effect of my arrested development
Here with you I'm trapped, I'm trapped, out of my element

I tear through all this wreckage
Wreckage you left when you dropped the bomb
Is there something worth saving
Or do I act, I act like nothing's wrong
The lesser of two evils gives me, gives me nothing at all

Lust and madness, murder and mayhem
My whole life's been about playing
It's all so surreal
Maybe that's why I touch but can't feel

Sittin' pretty, as I sit up straight
Trying to find means to an end I move into harms way
I move into harms way

I see my face in the mirror
I feel my feet but I can't seem to walk in my shoes
When it hurts I feel closer to you
Closer than you ever knew
And the bottom line is knowing
I will die and the worms will eat me
The bottom line is knowing
Ain't no one else I can be

Lust and madness, murder and mayhem
My whole life's been about playing
It's all so surreal
Maybe that's why I touch but can't feel

Sittin' pretty, as I sit up straight
Trying to find means to an end I move into harms way
Running steady, smile on my face
Trying to find means to an end I move into harms way
I move into harms way

Sittin' pretty as I, running steady as I, sittin' pretty as I sit up straight
Running steady, smile on my face
Trying to find means to an end I move into harms way
I move into harms way
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 600031;

int n,ans;
vector<int> g[N];

int used[N];
int subsize[N];

void dfs(int v){
	used[v]=1;
	subsize[v]=1;
	for (int i=0;i<g[v].size();i++){
		int to=g[v][i];
		if (used[to])
			continue;
		dfs(to);
		subsize[v]+=subsize[to];
	}
	if (v!=1&&subsize[v]%2==0)
		ans++;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n;
	if (n%2==1){
		cout<<-1<<endl;
		return 0;
	}

	for (int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs(1);

	cout<<ans<<endl;

//	cin.get(); cin.get();
	return 0;
}