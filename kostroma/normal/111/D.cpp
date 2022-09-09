#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <memory.h>
#include <algorithm>
#include <math.h>
using namespace std;

typedef long long li;
typedef long double ld;
typedef pair <int, int> pi;
typedef pair <li, li> pli;
typedef vector <int> vi;
typedef vector <li> vli;
#define mp make_pair
#define pb push_back
void solve ();
int main ()
{
#ifdef _DEBUG
	freopen ("in.txt", "r", stdin);
#endif
	int t=1;
	while (t--)
		solve ();
	return 0;
}
//caution: is int really int?
#define int li
int MOD=1000000007;
int n, m, k;
li dp[2000][2000];
int bp (int q, int w)
{
	if (w==0)
		return 1;
	if (w%2)
		return (q*bp (q, w-1))%MOD;
	int u=bp (q, w/2);
	return (u*u)%MOD;
}
int c (int q, int w)
{
	if (q<w)
		return 0;
	if (w<0)
		return 0;
	int verh=1;
	for (int i=q; i>q-w; i--)
	{
		verh*=i; verh%=MOD;
	}
	int niz=1;
	for (int i=2; i<=w; i++)
	{
		niz*=i; niz%=MOD;
	}
	int dom=bp ( niz, MOD-2 );
	return (dom*verh)%MOD;
}
void solve ()
{
	//freopen ("out.txt", "w", stdout);
	cin>>n>>m>>k;
	dp[0][0]=1LL;
	for (int i=0; i<n; i++)
		for (int j=0; j<=i; j++)
		{
			int cur=dp[i][j];
			dp[i+1][j]+=j*dp[i][j]; dp[i+1][j]%=MOD;
			dp[i+1][j+1]+=dp[i][j]; dp[i+1][j+1]%=MOD;
		}
	for (int i=0; i<=n; i++)
	{
		int cur=1;
		for (int j=0; j<=i; j++)
		{
			dp[i][j]*=cur;
			cur*=(j+1); cur%=MOD;
			dp[i][j]%=MOD;
		}
	}
	if (m==1)
	{
		li ans=1;
		for (int i=0; i<n; i++)
		{
			ans*=k; ans%=MOD;
		}
		cout<<ans;
		return;
	}

	if (m==2)
	{
		int answer=0;
		for (int l=1; l<=n && l<=k; l++)
		{
			int u=c(k, l);
			int now=u*u%MOD;
			now*=dp[n][l]; now%=MOD;
			now*=dp[n][l]; now%=MOD;
			answer+=now; answer%=MOD;
		}
		cout<<answer;
		return;
	}
	int ans=0;
	int z=1;
	for (int cur=1; cur<=k && cur<=n; cur++)
	{
		int thing=c(k, cur);
		for (int l=cur; l<=k && l<=n; l++)
			if (2*l-cur>k)
				break;
			else
		{
			int dob;
			//int z=c(k-cur, l-cur);
			//int p=c(k-l, l-cur);
			//int u=c(k, cur);
			dob=thing;
			dob*=dp[n][l]; dob%=MOD;
			dob*=dp[n][l]; dob%=MOD;
			dob*=bp (cur, (m-2)*n); dob%=MOD;
			ans+=dob; ans%=MOD;
			//if (l==cur)
			//cout<<l-cur<<" "<<cur<<endl<<dp[n][l]<<endl;
			thing*=(k-2*l+cur-1); thing%=MOD; thing*=(k-2*l+cur); thing%=MOD; thing*=bp (l+1-cur, 2*MOD-4); thing%=MOD;
		}
	}
	cout<<ans;
}