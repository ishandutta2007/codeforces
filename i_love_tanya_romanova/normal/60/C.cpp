/*
How do you look into the mirror
When you're too tired to fake a smile
Your misery won't make you look thinner
Reality is bitter
It's your hand and yours alone that has opened
The door to let their voice in
Into your head, under your skin
Fix your face or you will never fit in

Do you want me, do you want me
To burst your bubble now?
Do you want me, I will break it
Make it loud
(Make it loud)
Do you want me, do you want me
To break the paradigm
These rules were made by us
They break you up inside
And then will break in down

Army of dolls stole your reflection
Army of dolls stole all your perfect imperfections
Just shut them out, don't let them in
Into your head
Do you really think
Misery tastes so much sweeter
Served with perfect smile

Do you want me, do you want me
To burst your bubble now?
Do you want me, I will break it
Make it loud
(Make it loud)
Do you want me, do you want me
To break the paradigm
These rules were made by us
They break you up inside
And then will break in down

Don't you look into the mirror
Army of dolls made you so bitter
Make-up magpul follow the leader
Never have seen a face much sweeter

Don't you look into the mirror
Army of dolls made you so bitter
Make-up magpul follow the leader
Never have seen a face much sweeter

Do you want me, do you want me
To burst your bubble now?
Do you want me, I will break it
Make it loud
(Make it loud)
Do you want me, do you want me
To break the paradigm
These rules were made by us
They break you up inside
And then will break in down
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
#define bsize 512

using namespace std;

int pr[1<<20];
int n,m,a[1<<20],b[1<<20],G[1<<20],L[1<<20];
vector<int> g[1<<20];
int distinct;
vector<int> primes;
vector<int> component;
int used_prime[1<<20];
int used[1<<20];
int ans[1<<20];
int er,known[1<<20];
int put[1<<20];

int get_degree(int a,int b)
{
	int res=0;
	while (a%b==0)
	{
		res++;
		a/=b;
	}
	return res;
}

void update_used(int x)
{
	if (x==1)
		return;
	if (pr[x]==0)
	{
		used_prime[x]=1;
		return;
	}
	used_prime[pr[x]]=1;
	update_used(x/pr[x]);
}

int pw(int a,int b)
{
	if (b==0)
		return 1;
	return a*pw(a,b-1);
}

void dfs(int v)
{
	used[v]=1;
	component.push_back(v);
	
	for (int i=0;i<g[v].size();i++)
	{
		int id=g[v][i];
		int to;
		if (a[id]==v)
			to=b[id];
		else
			to=a[id];
		if (used[to])
			continue;
		dfs(to);
	}
}

int cur_prime;

void dfs1(int v,int deg)
{
	known[v]=1;
	put[v]=deg;
	for (int i=0;i<g[v].size();i++)
	{
		int id=g[v][i];
		int v1=get_degree(L[id],cur_prime);
		int v2=get_degree(G[id],cur_prime);
		if (deg!=v1&&deg!=v2)
		{
			er=1;
			return;
		}
		int to;
		if (a[id]==v)
			to=b[id];
		else
			to=a[id];
			
		int tdeg;
		
		if (deg==v1)
		{
			tdeg=v2;
		}
		else
			tdeg=v1;
		
		if (known[to])
		{
			if (put[to]!=tdeg)
			{
				er=1;return;
			}
		}
		else
		{
			dfs1(to,tdeg);
		}
	}
}

long long gcd(long long a,long long b)
{
	while (a&&b)a>b?a%=b:b%=a;
	return a+b;
}
long long lcm(long long a,long long b)
{
	return a/gcd(a,b)*b;
}

int main(){
//freopen("beavers.in","r",stdin);
//freopen("beavers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

pr[1]=1;
for (int i=2;i<=1000000;i++)
	if (pr[i]==0)
		for (int j=i*2;j<=1000000;j+=i)
		{
			pr[j]=i;
		}

cin>>n>>m;

for (int i=1;i<=m;i++)
{
	cin>>a[i]>>b[i]>>G[i]>>L[i];
	g[a[i]].push_back(i);
	g[b[i]].push_back(i);
	update_used(L[i]);
}

for (int i=2;i<=1000000;i++)
	if (used_prime[i])
	{
		++distinct;
		primes.push_back(i);
	}

if (distinct>1000)
{
	cout<<"NO"<<endl;
	return 0;
}


for (int i=1;i<=n;i++)
	ans[i]=1;
	
for (int i=1;i<=n;i++)
{
	if (used[i])
		continue;
	component.clear();
	dfs(i);
	
	if (component.size()==1)
	{
		ans[component[0]]=1;
		continue;
	}
	
	int id=component[0];
	
	int edge_id=g[id][0];
	
	for (int j=0;j<primes.size();j++)
	{
		er=0;
		
		cur_prime=primes[j];
		
		for (int q=0;q<component.size();q++)
		{
			int tv=component[q];
			known[tv]=0;
		}
		int var1=get_degree(G[edge_id],primes[j]);
		dfs1(id,var1);
		
		if (er==0)
		{
			for (int q=0;q<component.size();q++)
			{
				int tv=component[q];
				ans[tv]*=pw(primes[j],put[tv]);
			}
			continue;
		}
		
		er=0;
		var1=get_degree(L[edge_id],primes[j]);
		for (int q=0;q<component.size();q++)
		{
			int tv=component[q];
			known[tv]=0;
		}
		dfs1(id,var1);
		
		if (er)
		{
			cout<<"NO"<<endl;
			return 0;
		}
		
		for (int q=0;q<component.size();q++)
		{
			int tv=component[q];
			ans[tv]*=pw(primes[j],put[tv]);
		}
	}
}

for (int i=1;i<=m;i++)
{
	int val1=ans[a[i]];
	int val2=ans[b[i]];
	long long g=gcd(val1,val2);
	long long l=lcm(val1,val2);
	if (g!=G[i]||l!=L[i])
	{
		cout<<"NO"<<endl;
		return 0;
	}
}

cout<<"YES"<<endl;

for (int i=1;i<=n;i++)
{
	if(i>1)
		cout<<" ";
	cout<<ans[i];
}
cout<<endl;

//cin.get();cin.get();
return 0;}