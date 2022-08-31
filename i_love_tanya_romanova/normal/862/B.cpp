/*
Far beyond the road
Between your house and home
There is a churning storm
Of hailing burning bones

Tiny baby cries
Little, tiny pawn
In the profit gain
Tiny baby grows

Mother, who's your man
Is he doing what he can
To make a proper home, home
By overturning other stones, stones
Father, mighty man
Loves his little boys, boys
Shows them how to kill
To save his precious stones, stones

Far beyond the wheel
It steers your life around
We're driving flesh and blood
Deep into the ground, ground

Far beyond the wheel
It steers your life around
We're driving flesh and blood
Deep into the ground, ground
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

#define eps 1e-11
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 200031;

int n;
vector<int> g[N];
int used[N];
int cnt[N];

void dfs(int v,int clr){
	cnt[clr]++;
	used[v]=1;
	for (int i=0;i<g[v].size();i++)
	{
		int to=g[v][i];
		if (used[to])
			continue;
		dfs(to,clr^1);
	}
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for (int i=1;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs(1,0);

	cout<<1ll*cnt[0]*cnt[1]-(n-1)<<endl;

	cin.get(); cin.get();
	return 0;
}