/*
*/

//#pragma comment(linker, "/STACK:16777216")
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

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

using namespace std;

int get_len(int x)
{
	if (x==0)
		return 0;
	return get_len(x/10)+1;	
}

int L;
int ar[20][20];
long long ans;

vector<int> todig(int x)
{
	vector<int> res;
	while (x)
	{
		res.push_back(x%10);
		x/=10;
	}
	reverse(res.begin(),res.end());
	return res;
}

int renorm(int num,int ps)
{
	vector<int> v=todig(num);
	v[ps]=0;
	int res=0;
	for (int i=0;i<v.size();i++)
	{
		res=res*10+v[i];
	}
	return res;
}

int cnt[7][7][101000];
vector<int> primes;
int pr[150000];

long long SOLVE()
{
	long long ways=1;
	for (int i=1;i<L;i++)
	{
		int cur=0;
		for (int j=0;j<L;j++)
		{
			cur=cur*10+ar[i][j];
		}
		ways=ways*cnt[L][i][cur];
	}
	return ways;
}

void dfs(int row,int col,int flag)
{
	//cout<<row<<" "<<col<<" "<<L<<endl;
	
	if (row==L||(row==L-1&&col>=L))
	{
		ans+=SOLVE();
		return;
	}
	for (int i=0;i<10;i++)
	{
		if (col==L-1&&(i%2==0||i==5)&&flag==1)
			continue;
		ar[row][col]=ar[col][row]=i;
		if (col==L-1)
			dfs(row+1,row+2,0);
		else
			dfs(row,col+1,flag|(i>0));	
	}
}

void solve(int num,int len)
{
	for (int i=0;i<5;i++)
	{
		for (int j=0;j<5;j++)
		{
			ar[i][j]=0;
		}
	}
	
	vector<int> v=todig(num);
	for (int i=0;i<len;i++)
	{
		ar[0][i]=ar[i][0]=v[i];
	}
	dfs(1,2,0);
}

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	pr[1]=1;
	for (int i=2;i<=100000;i++)
	{
		if (pr[i]==0)
		{
			for (int j=i*2;j<=100000;j+=i)
			{
				pr[j]=1;
			}
		}
	}
	
	for (int i=1;i<=100000;i++)
	{
		if (pr[i]==0)
			primes.push_back(i);
	}
	
	for (int i=0;i<primes.size();i++)
	{
		int cur_len=get_len(primes[i]);
		for (int ps=0;ps<cur_len;ps++)
		{
			int here=renorm(primes[i],ps);
			for (int j=cur_len;j<=5;j++)
			{
				cnt[j][ps+(j-cur_len)][here]++;
			}
	//		cnt[cur_len][ps][renorm(primes[i],ps)]++;
		}
		for (int len=cur_len+1;len<=5;len++)
		{
			for (int rem_ps=0;rem_ps<len-cur_len;rem_ps++)
			{
				cnt[len][rem_ps][primes[i]]++;
			}
		}
	}
	
//	cout<<cnt[3][1][1]<<endl;
	
	int tests;
	
	cin>>tests;
	for (;tests;--tests)
	{
		int n;
		cin>>n;
		L=get_len(n);
		ans=0;
		solve(n,L);
		cout<<ans<<endl;
	}
	
	cin.get(); cin.get();
	return 0;
}