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
const int N = 1000031;

int n;
long long cnt[N];

long long SUM2[N],SUM[N];

long long pw2[N],pw10[N];

vector<int> val_list;

long long get_dig(int val,int ps)
{
	val%=pw10[ps+1];
	return val/pw10[ps];
}

int pcount(int x)
{
	if (x==0)
		return 0;
	return pcount(x/2)+x%2;
}

bool is_over(int a,int b) // a over b
{
	for (int i=0;i<6;i++)
	{
		if (get_dig(a,i)<get_dig(b,i))
			return false;
	}
	return true;
}

int cnt_over(int val)
{
	return cnt[val];

	int res=0;
	for (int i=0;i<val_list.size();i++)
	{
		if (is_over(val_list[i],val))
			++res;
	}
	return res;
}

long long get_squares_above(int val)
{
	return SUM2[val];

	long long res=0;
	for (int i=0;i<val_list.size();i++)
	{
		if (is_over(val_list[i],val))
			res+=1ll*val_list[i]*val_list[i];
		res%=bs;
	}
	return res%bs;
}

long long get_s_above(int val)
{
	return SUM[val];
	long long res=0;
	for (int i=0;i<val_list.size();i++)
	{
		if (is_over(val_list[i],val))
			res+=1ll*val_list[i];
		res%=bs;
	}
	return res%bs;
}

void add(long long &a,long long b)
{
	a+=b;
	if (a>=bs)
		a-=bs;
}

int PC[2000];

int PREC_ADD[N];

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	for (int i=0;i<100;i++)
	{
		PC[i]=pcount(i);
	}

	pw2[0]=1;
	for (int i=1;i<N;i++)
	{
		pw2[i]=pw2[i-1]*2%bs;
	}

	pw10[0]=1;
	for (int i=1;i<10;i++)
	{
		pw10[i]=pw10[i-1]*10%bs;
	}

	for (int i=0;i<64;i++)
	{
		int s=0;
		for (int j=0;j<6;j++)
		{
			if (i&(1<<j))
				s+=pw10[j];
		}
		PREC_ADD[i]=s;
	}

	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		int val;
		scanf("%d",&val);
		val_list.push_back(val);
		cnt[val]++;
	}

	for (int i=0;i<1000000;i++)
	{
		SUM[i]=cnt[i]*1ll*i%bs;
		SUM2[i]=cnt[i]*1ll*i%bs*i%bs;
	}

	for (int ps=0;ps<6;ps++)
	{
		for (int i=0;i<1000000;i++)
		{
			int here=get_dig(i,ps);
			for (int q=0;q<here;q++)
			{
				int val2=i-pw10[ps]*here+pw10[ps]*q;
				add(SUM[val2],SUM[i]);
				add(SUM2[val2],SUM2[i]);
				add(cnt[val2],cnt[i]);
			}
		}
	}

	//cout<<clock()*1.0/CLOCKS_PER_SEC<<endl;

	long long ans=0;

	for (int i=0;i<1000000;i++)
	{
		long long res=0;

		if (cnt_over(i)==0)
			continue;
		int bad_mask=0;
		for (int j=0;j<6;j++)
		{
			if (get_dig(i,j)==9)
				bad_mask|=(1<<j);
		}

		for (int mask=0;mask<(1<<6);mask++)
		{
			int here=i;
			int ok=1;

			if (mask&bad_mask)
				ok=0;

			here+=PREC_ADD[mask];

			if (ok==0)
				continue;
			long long cnt_above=cnt_over(here);
			if (cnt_above==0)
				continue;

			long long s_squares_above=get_squares_above(here);
			long long s_above=get_s_above(here);

			long long addend_here=0;

			if (cnt_above==1)
			{
				addend_here=s_squares_above;
			}
			else
			{
				long long ways=pw2[cnt_above-2];
				addend_here=ways*1ll*(s_squares_above+s_above*s_above%bs)%bs;
			}

			if (PC[mask]%2==0)
				res+=addend_here;
			else
				res-=addend_here;

			if (res<0)
				res+=bs;
			if (res>=bs)
				res-=bs;
		}
		if (res!=0)
		{
			ans^=(1ll*res*i);
		//	cout<<i<<" "<<res<<" "<<1ll*res*i<<endl;
		}
	}

	//cout<<clock()*1.0/CLOCKS_PER_SEC<<endl;
	cout<<ans<<endl;

	cin.get(); cin.get();
	return 0;
}