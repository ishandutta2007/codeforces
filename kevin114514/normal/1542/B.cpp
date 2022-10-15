#include<bits/stdc++.h>
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
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n,a,b;
		cin>>n>>a>>b;
		if(a==1)
		{
			if((n-1)%b==0)
				puts("Yes");
			else	puts("No");
		}
		else
		{
			ll x=1;
			bool ok=false;
			for(ll i=0;x<=n;i++)
			{
				if((n-x)%b==0)
					ok=true;
				x*=a;
			}
			if(ok)
				puts("Yes");
			else	puts("No");
		}
	}
	return 0;
}