#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define setpre(n) std::cout << std::fixed << std::setprecision(n);
#define pb(a) push_back(a);
int main()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
	int t=1;
//	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		ll a,b;
		cin>>a>>b;
		int in,ans;
		bool f=0;
		ll n=(s[0]-'0'),r,p=1;
		vector <int> ai;
		FOR(i,1,s.size())
		{
			r=n%a;
			if(r==0 && s[i]!='0')
			{
				ai.pb(i);
			}
			n=r*10+(s[i]-'0');
		}
		in=ai.size()-1;
		if(in<0)
		{
			cout<<"NO";
			return 0;
		}
		int l=s.size();
		n=s[l-1]-'0';
		FOR(i,1,l)
		{
			r=n%b;
			if(r==0)
			{
				if(ai[in]==l-i)
				{
					ans=l-i;
					f=1;
					break;
				}
			}
			p=p*10%b;
			n=((s[l-1-i]-'0')*p+r);
			if(ai[in]==l-i)
			in--;
			if(in<0)
			break;
		}
		if(f)
		cout<<"YES\n";
		else
		{
			cout<<"NO";
			return 0;
		}
		FOR(i,0,l)
		{
			if(i==ans)
			cout<<"\n";
			cout<<s[i];
		}
	}
}