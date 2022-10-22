#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
ll a[maxn],b[maxn];
ll sum=0;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
ll solve(){return ceil((sum+b[1])*0.5);}
int main(){
	int n;
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=a[i]-a[i-1];
	for(int i=2;i<=n;i++)if(b[i]>0)sum+=b[i];
	printf("%lld\n",solve());
	int Q;
	Q=read();
	while(Q--){
		int l,r,x;
		l=read();r=read();x=read();
		if(l>1&&b[l]>0)sum-=b[l];if(r<n&&b[r+1]>0)sum-=b[r+1];
		b[l]+=x;b[r+1]-=x;
		if(l>1&&b[l]>0)sum+=b[l];if(r<n&&b[r+1]>0)sum+=b[r+1];
		printf("%lld\n",solve());
	}
    return 0;
}