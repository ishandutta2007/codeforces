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
void die(string S){puts(S.c_str());exit(0);}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x,p,k;
		cin>>x>>p>>k;
		x++;
		int l=x,r=1e9;
		vector<int> pr;
		for(int i=2;i<=sqrt(p);i++)
			if(p%i==0)
			{
				pr.pb(i);
				while(p%i==0)
					p/=i;
			}
		if(p>1)
			pr.pb(p);
		int n=sz(pr);
		while(l<r)
		{
			int mid=(l+r)/2;
			int cnt=0;
			for(int i=0;i<(1<<n);i++)
			{
				int y=1;
				for(int j=0;j<n;j++)
					if(i>>j&1)
						y*=pr[j];
				int m1=(x+y-1)/y,m2=mid/y;
				cnt+=(m2-m1+1)*((__builtin_popcount(i)%2)?-1:1);
			}
			if(cnt>=k)
				r=mid;
			else	l=mid+1;
		}
		cout<<l<<endl;
	}
	return 0;
}