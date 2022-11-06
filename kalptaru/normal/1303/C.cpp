#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll m1=1000000007;
ll m2=67280421310721;
char small[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
ll po(ll a,ll b)
{
	ll res=1;
	a=a%m1;
	while(b)
	{
		if(b%2==1)
		res=((res*a)%m1);
		a=((a*a)%m1);
		b>>=1;
	}
	return res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
	cin>>test;
	while(test--)
	{
		string s;
		cin>>s;
		int o[100];
		bool c[26]={0},f=1;
		FOR(i,0,100)
		o[i]=-1;
		int p=50;
		c[s[0]-'a']=1;
		o[p]=s[0]-'a';
		int l=0;
		FOR(i,1,s.size())
		{
//			cout<<p<<' ';
			l=(s[i]-'a');
			if(c[l])
			{
				if(o[p+1]==l)
				{
					p++;
				}
				else if(o[p-1]==l)
				{
					p--;
//					cout<<'[';
				}
				else
				{
					f=0;
//					cout<<i;
					break;
				}
			}
			else
			{
				c[l]=1;
				if(o[p+1]==-1)
				{
					p++;
					o[p]=l;
				}
				else if(o[p-1]==-1)
				{
					p--;
					o[p]=l;
				}
				else
				{
					f=0;
//					cout<<i<<' '<<o[49];
					break;
				}
			}
//			cout<<p<<' ';
		}
		if(f==0)
		{
			cout<<"NO"<<'\n';
			continue;
		}
		else
		{
			cout<<"YES"<<'\n';
		}
		FOR(i,0,100)
		{
			if(o[i]!=-1)
			{
				cout<<small[o[i]];
			}
		}
		FOR(i,0,26)
		{
			if(c[i]==0)
			cout<<small[i];
		}
		cout<<'\n';
	}
	return 0;
}