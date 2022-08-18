/*
Wishing never got us what we needed
So we waited for our salvation to arrive
Then it took everything that we loved
And it let us alive

I hear you call
And I promise to you
One day, some day
The pain will go

Solitary movement meant for two
Can you hear the loneliness in silent cries
If you take everyting that I love
Leave me to die

I hear you call
And I promise to you
One day, some day
The pain will go

If you take everything that I love
And you leave here
Leave me alive
If you take everything thet I love
And I'm standing here
Waiting to die

I hear you call
And I promise to you
One day, some day
The pain will go
*/

//#pragma comment(linker, "/STACK:16777216")
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
#include <ctime> 
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 2
#define N 300505

using namespace std;

int n;
vector<int> ve[N];
int L[N],R[N];
vector<pair<int, int> >block[N];
int ql,qr,qval;
int ar[N];
vector<int> primes;
int pr[1<<20];
int tests;
int ans[N];
int cnt[1<<20];
int IN[1<<20];
int t[1<<22];
vector<int> queries[1<<20];
int pref[N];
int le[1<<20];


void build(int v,int tl,int tr)
{
	t[v]=1;
	if (tl==tr)	
		return;
	int tm=tl+tr;
	tm/=2;
	build(v*2,tl,tm);
	build(v*2+1,tm+1,tr);
}

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

int RAND()
{
	int res=0;
	for (int i=0;i<30;i++)
		res=res*2+rand()%2;
	return res;
}

vector<int> fact(int x)
{
	vector<int> res;
	while (x>1)
	{
		res.push_back(pr[x]);
		x/=pr[x];
	}
	return res;
}

void mult(int v,int tl,int tr,int ps,int val)
{
	if (tl==tr)
	{
		t[v]=1ll*t[v]*val%bs;
		return;
	}
	int tm=tl+tr;
	tm/=2;
	if (ps<=tm)
		mult(v*2,tl,tm,ps,val);
	else
		mult(v*2+1,tm+1,tr,ps,val);
	t[v]=1ll*t[v*2]*t[v*2+1]%bs;
}

int get(int v,int tl,int tr,int l,int r)
{
	if (tl==l&&tr==r)
		return t[v];
	if (l>r)
		return 1;
	int tm=tl+tr;
	tm/=2;
	int res1=get(v*2,tl,tm,l,min(r,tm));
	int res2=get(v*2+1,tm+1,tr,max(tm+1,l),r);
	return 1ll*res1*res2%bs;
}

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	IN[1]=1;
	for (int i=2;i<(1<<20);i++)
		IN[i]=(bs-1ll*(bs/i)*IN[bs%i]%bs)%bs;
	
	pr[1]=1;
	for (int i=2;i<=1000000;i++)
		if (pr[i]==0)
			for (int j=i;j<=1000000;j+=i)
				pr[j]=i;
	
	for (int i=2;i<=1000000;i++)
		if (pr[i]==i)
			primes.push_back(i);
		
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>ar[i];
		//ar[i]=RAND()%1000000+1;
		ve[i]=fact(ar[i]);
	}
	
	cin>>tests;
	for (int i=1;i<=tests;i++)
	{
		cin>>L[i]>>R[i];
	//	L[i]=RAND()%bsize;
	//	R[i]=n-RAND()%bsize;
		queries[R[i]].push_back(i);
	}
	
	pref[0]=1;
	for (int i=1;i<=n;i++)
		pref[i]=1ll*pref[i-1]*ar[i]%bs;
	
	build(1,1,n);
	
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<ve[i].size();j++)
		{
			int val=ve[i][j];
			if (le[val]==i)
				continue;
			if (le[val]>0)
			{
				int TT=1ll*IN[val-1]*val%bs;
				mult(1,1,n,le[val],TT);
			}
			int TT=1ll*IN[val]*(val-1)%bs;
			mult(1,1,n,i,TT);
			le[val]=i;
		}
		for (int j=0;j<queries[i].size();j++)
		{
			int id=queries[i][j];
			int have=pref[i];
			have=1ll*have*inv(pref[L[id]-1])%bs;
			//cout<<"@"<<id<<" "<<have<<endl;
			
			have=1ll*have*get(1,1,n,L[id],R[id])%bs;
			ans[id]=have;
		}
	}
	
	for (int i=1;i<=tests;i++)
	{
		cout<<ans[i]<<"\n";
	}
	
	return 0;
}