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
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define lb(v,x) (lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (upper_bound(ALL(v),x)-v.begin())
void die(string S){puts(S.c_str());exit(0);}
ll a[110];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<2;i++)
		{
			ll gcd=0;
			for(int j=i;j<n;j+=2)
				gcd=__gcd(a[j],gcd);
			for(int j=i^1;j<n;j+=2)
				if(a[j]%gcd==0)
					goto failed;
			cout<<gcd<<endl;
			goto success;
			failed:;
		}
		cout<<0<<endl;
		success:;
	}
	return 0;
}