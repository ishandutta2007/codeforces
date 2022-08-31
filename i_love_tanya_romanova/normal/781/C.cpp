/*
Never too soon to be through
Being cool too much too soon
Too much for me too much for you
You're gonna loose in time
Every turn looking to burn
Some never learn live and learn
Stop your searching for a curse
Before you end up in a hearse
Don't be afraid to show your friends
That you hurt inside inside
Pain's part of life don't hide behind your false pride
It's a lie your lie
Don't slip away and don't forget
I'll give you more than you can get
It's so lonely when you don't even know
Yourself come to me
If you see me getting mighty
If you see me getting high
Knock me down
I'm not bigger than life
I'm tired of being untouchable
I'm not above the love
I'm part of you and you're part of me
Why did you go away
Too late to tell you how i feel
I want you back but i get real
Can you hear my falling tears
Making rain where you lay
Finding what you're looking for
Can end up being such a bore
I pray for you most every day
My love's with you now fly away
If you see me getting mighty
If you see me getting high
Knock me down
I'm not bigger than life
It's so lonely when you don't even know yourself
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
#define bs 1000000007
#define bsize 512

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 700031;

int n,m,k;
vector<int> order;
vector<int> g[N];
int used[N];

vector<int> ans[N];

void dfs(int v)
{
	order.push_back(v);
	used[v]=1;
	for (int i=0;i<g[v].size();i++)
	{
		int to=g[v][i];
		if (used[to])
			continue;
		dfs(to);
		order.push_back(v);
	}
//	order.push_back(v);
}

vector<int> normalize(vector<int> v){
	vector<int> ret;
	for (int i=0;i<v.size();i++)
	{
		if (i==0||v[i]!=v[i-1])
			ret.push_back(v[i]);
	}
	return ret;
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)
	{
		int a,b;
//		cin>>a>>b;
		scanf("%d",&a);
		scanf("%d",&b);
		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs(1);

	int per_one=2*n/k+(2*n%k>0);

	int ptr=0;

	/*for (int i=0;i<order.size();i++)
	{
		cout<<order[i]<<" ";
	}
	cout<<endl;
*/
	for (int i=0;i<order.size();i+=per_one)
	{
		for (int j=i;j<i+per_one&&j<order.size();j++)
		{
			ans[ptr].push_back(order[j]);
		}
		++ptr;
	}

	for (int i=0;i<k;i++)
	{
		ans[i]=normalize(ans[i]);
	}

	for (int i=0;i<k;i++)
	{
		if (ans[i].size()==0)
			ans[i].push_back(1);
	}

	for (int i=0;i<k;i++)
	{
		printf("%d",ans[i].size());
		for (int j=0;j<ans[i].size();j++)
		{
			printf(" %d",ans[i][j]);
		}
		printf("\n");
	}

	cin.get(); cin.get();
	return 0;
}