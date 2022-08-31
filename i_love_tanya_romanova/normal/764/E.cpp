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
#define BS 12345678891
#define bsize 512

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 500031;

int n,m;
int ar[N];
int used[N];

void make_complement()
{
	for (int i=0;i<m;i++)
	{
		used[i]=0;
	}

	for (int i=0;i<n;i++)
	{
		used[ar[i]]=1;
	}

	vector<int> vals;
	for (int i=0;i<m;i++)
	{
		if (used[i]==0)
			vals.push_back(i);
	}

	n=vals.size();
	for (int i=0;i<n;i++)
	{
		ar[i]=vals[i];
	}
}

set<int> have;

int count_entries(int dif)
{
	int res=0;
	for (int i=0;i<n;i++)
	{
		int othr=ar[i]-dif+m;
		othr%=m;
		if (have.find(othr)!=have.end())
			++res;
		othr=ar[i]+dif;
		othr%=m;
		if (have.find(othr)!=have.end())
			++res;
		have.insert(ar[i]);
	}
	return res;
}

long long pw(long long a,long long b)
{
	if (b==0)
		return 1;
	if (b%2)
		return a*pw(a,b-1)%m;
	return pw(a*a%m,b/2);
}

int inv(int x)
{
	return pw(x,m-2);
}

pair<int,int> solver(){
	sort(ar,ar+n);
	if (n==1)
	{
		return make_pair(ar[0],1);
	}
	if (n==0)
		return make_pair(1,1);

	int D=ar[1]-ar[0];
	int Q=count_entries(D);
	// 1=n-1,2=n-2...
	int real_D=1ll*D*inv(n-Q)%m;
	int cur=1;
	int FE=ar[0];
	for (int l_dif=1;;l_dif++)
	{
		long long should_be=ar[0]-1ll*real_D*l_dif;
		should_be=should_be%m+m;
		should_be%=m;
		if (have.find(should_be)==have.end())
			break;
		cur++;
		FE=should_be;
	}

	for (int r_dif=1;;r_dif++)
	{
		long long should_be=ar[0]+1ll*real_D*r_dif;
		should_be=should_be%m+m;
		should_be%=m;
		if (have.find(should_be)==have.end())
			break;
		cur++;
	}
	if (cur!=n)
		return make_pair(-1,-1);
	return make_pair(FE,real_D);
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>m>>n;
	for (int i=0;i<n;i++)
	{
		cin>>ar[i];
	}

	if (n*2>m)
	{
		int old_n=n;
		make_complement();
		pair<int,int> q=solver();
		if (q.first==-1)
			cout<<-1<<endl;
		else
		{
			q.first=(q.first+1ll*(m-old_n)*q.second)%m;
			cout<<q.first<<" "<<q.second<<endl;
		}
	}
	else
	{
		pair<int,int> p=solver();
		if (p.first==-1)
			cout<<-1<<endl;
		else
		{
			cout<<p.first<<" "<<p.second<<endl;
		}
	}

	cin.get(); cin.get();
	return 0;
}