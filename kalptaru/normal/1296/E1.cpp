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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
//	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		string s;
		cin>>s;
		int c[n]={0};
		int m=0,l=0;
		FOR(i,0,26)
		{
			m=0;
			bool v[26]={0};
			FOR(j,0,n)
			{
				if((s[j]-'a')==(25-i))
				{
					c[j]=m+1;
				}
				if((s[j]-'a')>(25-i))
				{
					v[c[j]-1]=1;
					while(v[m])
					m++;
				}
			}
		}
		FOR(i,0,n)
		l=max(l,c[i]);
		if(l>2)
		cout<<"NO";
		else
		{
			cout<<"YES"<<'\n';
			FOR(i,0,n)
			cout<<c[i]-1;
		}
	}
	return 0;
}