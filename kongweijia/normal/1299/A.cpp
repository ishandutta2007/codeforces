#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100000
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int a[maxn+5];

int main()
{
	int n; scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	per(d,0,30) 
	{
		int cnt=0;
		rep(i,1,n) if((a[i]>>d)&1) cnt++;
		if(cnt==1)
		{
			rep(i,1,n) if((a[i]>>d)&1) swap(a[1],a[i]);
			break;
		}
	}
	rep(i,1,n) printf("%d%c",a[i]," \n"[i==n]);
	return 0;
}