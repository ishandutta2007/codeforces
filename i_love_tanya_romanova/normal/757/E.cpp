/*
When night slowly spread its blackened wings
and breathe out chilly moist and mist,
I experience an obsession
of evil which I worship

I can feel the night
caress my body with it's beauty,
and the cold dead light
from the moon upon the black sky.
Night is all around me
as I drown in delight.
Oh night, I'm overwhelmed
by thy majestic might.

Under the mighty wings of blackness
I deny my earthly existence.
Embraced by thy nocturnal paradise
I will forever belong to the night.

It's time to breathe
the seents of the night.
I opened my veins
to let the night in and I came...

When night slowly spread its blackened wings
and breathe out chilly moist and mist,
I experience an obsession
of evil which I worship

I can feel the night
caress my body with it's beauty,
and the cold dead light
from the moon upon the black sky.
Night is all around me
as I drown in delight.
Oh night, I'm overwhelmed
by thy majestic might.
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
#define bs 1000000007
#define bsize 512

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 1000031;

int pr[N];

set<vector<int> > S;
set<vector<int> >::iterator it;

vector<int> parse(int x){
	vector<int> ret;
	while (x>1)
	{
		int q=pr[x];
		int cnt=0;
		while (x%q==0)
		{
			cnt++;
			x/=q;
		}
		ret.push_back(cnt);
	}
	sort(ret.begin(),ret.end());
	return ret;
}


int B[100];

int tests;

long long dp[200][200];

long long fact[N],invf[N];

long long pw(long long a,long long b)
{
if (b==0)
	return 1;
if (b%2)
	return a*pw(a,b-1)%bs;
return pw(a*a%bs,b/2);
}

long long inv(long long x)
{
	return pw(x,bs-2);
}

long long C(long long n,long long m)
{
	if (m>n)
		return 0;
	long long res=fact[n]*invf[m];
	res%=bs;
	res*=invf[n-m];
	return res%bs;
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//	freopen("F:/input.txt", "r", stdin);
	//	freopen("F:/output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	fact[0]=1;
	for (int i=1;i<N;i++)
	{
		fact[i]=fact[i-1]*i%bs;
	}
	invf[N-1]=inv(fact[N-1]);
	for (int i=N-2;i>=0;--i)
	{
		invf[i]=invf[i+1];
		invf[i]*=(i+1);
		invf[i]%=bs;
	}

	pr[1]=1;
	for (int i=2;i<N;i++)
	{
		if (pr[i]==0)
		{
			for (int j=i;j<N;j+=i)
			{
				pr[j]=i;
			}
		}
	}

	/*for (int i=1;i<N;i++)
	{
		vector<int> V=parse(i);
		S.insert(V);
	}*/

	/*cout<<S.size()<<endl;

	for (it=S.begin();it!=S.end();it++)
	{
		vector<int> here=(*it);
		for (int i=0;i<here.size();i++)
		{
			cout<<here[i]<<" ";
		}
		cout<<endl;
	}
*/
	/*for (int i=1;i<=100;i++)
	{
		vector<int> Q=parse(i);
		dp[0][i]=(1<<Q.size());
	}

	int n;
	cin>>n;

	for (int iter=1;iter<=10;iter++)
	{
		for (int i=1;i<=500;i++)
		{
			for (int j=1;j<=i;j++)
			{
				if (i%j==0)
				{
					dp[iter][i]+=dp[iter-1][j];
				}
			}
		}
		cout<<dp[iter][n]<<endl;
	}

/*
	scanf("%d",&tests);
	for (int test=1;test<=tests;test++)
	{
		scanf("%d",&lev[test]);
		scanf("%d",&val[test]);
		qu_list[lev[test]].push_back(test);
	}

	for (int i=0;i<=20;i++)
	{
		dp[0][i]=2;
	}

	dp[0][0]=1;

	for (int i=0;i<=20;i++)
	{
		B[i]=min(i-1,20-i);
	}

	for (int iter=0;iter<=5;iter++)
	{
		for (int i=0;i<=20;i++)
		{
			for (int j=0;j<=B[i];j++)
			{
				dp[iter+1][i+j]+=dp[iter][i]*dp[iter][j]*2;
				if (dp[iter+1][i+j]>15e18)
					dp[iter+1][i+j]%=bs;
			}
		}
		for (int i=0;i<=10;i++)
		{
			dp[iter+1][i*2]+=dp[iter][i]*dp[iter][i];
		}
		for (int i=0;i<=20;i++)
		{
			if (dp[iter+1][i]>=bs)
				dp[iter+1][i]%=bs;
		}
		for (int q=1;q<=20;q++)
		{
			cout<<dp[iter][q]<<" ";
		}
		cout<<endl;

		for (int i=0;i<qu_list[iter].size();i++)
		{
			int id=qu_list[iter][i];
			int here=val[id];
			ans[id]=1;
			while (here>1)
			{
				int cnt=0;
				int d=pr[here];
				while (here%d==0)
				{
					cnt++;
					here/=d;
				}
				ans[id]=ans[id]*dp[iter][cnt]%bs;
			}
			cout<<id<<" "<<ans[id]<<endl;
		}

	}*/

	/*int a,b;

	while (cin>>a>>b)
	{
		cout<<C(a,b)<<endl;
	}*/

	scanf("%d",&tests);
	for (;tests;--tests)
	{
		int lev,val;
		scanf("%d",&lev);
		scanf("%d",&val);
		vector<int>V=parse(val);
		if (lev==0)
		{
			printf("%d\n",(1<<V.size()));
			continue;
		}

		if (val==1)
		{
			printf("1\n");
			continue;
		}

		for (int i=0;i<=V.size();i++)
		{
				for (int taken_bits=0;taken_bits<=i;taken_bits++)
				{
					dp[i][taken_bits]=0;
				}
		}
		dp[0][0]=1;

		for (int ps=0;ps<V.size();ps++)
		{
			for (int here=0;here<=V[ps];here++)
			{
				for (int old_bits=0;old_bits<=ps;old_bits++)
				{
					long long ways_here=C(V[ps]+lev-1-here,lev-1);
					ways_here*=dp[ps][old_bits];
					dp[ps+1][old_bits+(here>0)]+=ways_here;
					dp[ps+1][old_bits+(here>0)]%=bs;
				}
			}
		}
		int ans=0;

		for (int i=0;i<=V.size();i++)
		{
		//	cout<<"%"<<val<<" "<<i<<" "<<dp[V.size()][i]<<endl;

			ans+=dp[V.size()][i]*(1ll<<i)%bs;
			if (ans>=bs)
				ans-=bs;
		}
		printf("%d\n",ans);
	}

	cin.get(); cin.get();
	return 0;
}