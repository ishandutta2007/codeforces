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
const int N = 111031;

int n,k;
set<long long> S;
set<long long> ::iterator it;
vector<long long> interesting;

map<long long, int> cnt;
int ar[N];

int main(){
//	freopen("explosion.in","r",stdin);
//	freopen("explosion.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>k;

	long long cur_prod=1;

	for (int iter=1;iter<=100;iter++)
	{
		S.insert(cur_prod);
		cur_prod*=k;
		if (cur_prod>1e16||cur_prod<-1e16)
			break;
	}

	for (it=S.begin();it!=S.end();it++)
	{
		interesting.push_back(*it);
	}

	cnt[0]=1;
	long long cur_s=0;
	long long ans=0;

	for (int i=1;i<=n;i++)
	{
		cin>>ar[i];
		cur_s+=ar[i];
		for (int j=0;j<interesting.size();j++)
		{
			ans+=cnt[cur_s-interesting[j]];
		}
		cnt[cur_s]++;
	}

	cout<<ans<<endl;

	cin.get(); cin.get();
	return 0;
}