
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