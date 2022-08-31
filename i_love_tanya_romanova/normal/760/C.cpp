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

#define eps 1e-11
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 200031;

int n,p[N],b[N],cycles;
int used[N];

void dfs(int v)
{
	if (used[v])
		return ;used[v]=1;
	dfs(p[v]);
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>p[i];
	}

	for (int i=1;i<=n;i++)
	{
		cin>>b[i];
	}

	for (int i=1;i<=n;i++)
	{	if (used[i])
			continue;
		dfs(i);
		++cycles;
	}

	if (cycles==1)
		cycles=0;

	int s=0;

	for (int i=1;i<=n;i++)
		s+=b[i];
	s%=2;
	if (s==0)
		++cycles;
	cout<<cycles<<endl;

	cin.get(); cin.get();
	return 0;
}