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
ll b[40400];
ll a[40400];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>b[i];
		ll S=0;
		for(int i=0;i<n;i++)
			S+=b[i];
		if(S%(n*(n+1)/2))
			goto fail;
		S/=(n*(n+1)/2);
		for(int i=0;i<n;i++)
		{
			ll del=b[(i+1)%n]-b[i];
			del=S-del;
			if(del%n||del<=0)
				goto fail;
			del/=n;
			a[(i+1)%n]=del;
		}
		puts("YES");
		for(int i=0;i<n;i++)
			cout<<a[i]<<" ";
		puts("");
		continue;
		fail:;
		puts("NO");
	}
	return 0;
}