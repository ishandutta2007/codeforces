#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
void die(string S){puts(S.c_str());exit(0);}
int calc(ll x,ll y)
{
	string s,t;
	while(x)
	{
		s+='0'+x%10;
		x/=10;
	}
	while(y)
	{
		t+='0'+y%10;
		y/=10;
	}
	rev(s);
	rev(t);
	int j=0;
	int i=0;
	while(i<s.length()&&j<t.length())
		if(s[i]==t[j])
		{
			i++;
			j++;
		}
		else	i++;
	return s.length()-j+t.length()-j;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll x;
		cin>>x;
		int ans=1e9;
		for(int i=0;i<60;i++)
			ans=min(ans,calc(x,(1ll<<i)));
		cout<<ans<<endl;
	}
	return 0;
}