/*
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

#define eps 1e-15
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 200031;

int n,m;

int gcd(int a,int b)
{
	while (a&&b)a>b?a%=b:b%=a;
	return a+b;
}

vector<int> group[N];

vector<int> G[N];
int is_banned[N];

int GROUP_SIZE[N];

int done[N];
int memo[N];
int next_step[N];

int rev(int x, int m)
{
    if (x == 1) return 1;
    return (1 - rev(m % x, x) * (long long)m) / x + m;
}

int go(int x, int y, int m)
{
    int g = __gcd(x, m);
    x /= g;
    y /= g;
    m /= g;
    return y * (long long)rev(x, m) % m;
}

int solve(int val)
{
	if (done[val])
		return memo[val];

	done[val]=1;
	memo[val]=GROUP_SIZE[val];
	next_step[val]=-1;

	for (int j=val*2;j<=m;j+=val)
	{
		int path=solve(j);
		if (path+GROUP_SIZE[val]>memo[val])
		{
			memo[val]=path+GROUP_SIZE[val];
			next_step[val]=j;
		}
	}
	return memo[val];
}

vector<int> ans;

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>m;

	for (int i=0;i<m;i++)
	{
		int here=gcd(i,m);
		group[here].push_back(i);
	}

	for (int i=1;i<=m;i++)
	{
		for (int j=i*2;j<=m;j+=i)
		{
			G[i].push_back(j);
		}
	}

	for (int i=1;i<=n;i++)
	{
		int val;
		cin>>val;
		is_banned[val]=1;
	}

	for (int i=1;i<=m;i++)
	{
		int good_in_group=0;
		for (int j=0;j<group[i].size();j++)
		{
			int val=group[i][j];
			if (is_banned[val])
				continue;
			good_in_group++;
		}
		GROUP_SIZE[i]=good_in_group;
		//cout<<i<<" "<<GROUP_SIZE[i]<<endl;
	}

	int res=solve(1);

//	cout<<res<<endl;

	int cur_prod=1;
	int cur_group=1;

	while (true)
	{
		for (int i=0;i<group[cur_group].size();i++)
		{
			int val=group[cur_group][i];
			if (is_banned[val])
				continue;
			int Z=go(cur_prod,val,m);
			ans.push_back(Z);
			cur_prod=val;
		}
		if (next_step[cur_group]==-1)
			break;
		cur_group=next_step[cur_group];
	}

	cout<<ans.size()<<endl;

	//int Q=1;

	for (int i=0;i<ans.size();i++)
	{
		if (i)
			cout<<" ";
		cout<<ans[i];
//		Q=Q*ans[i]%m;
//		cout<<"@"<<Q<<endl;
	}
	cout<<endl;

	cin.get(); cin.get();
	return 0;
}