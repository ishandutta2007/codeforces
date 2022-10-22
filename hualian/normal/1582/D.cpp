#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define int long long
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=1e5+10;
int n,a[N];
void solve(int l){
	for(int i=l;i<=n;i+=2){
		printf("%lld %lld ",-a[i+1],a[i]);
	}
}
signed main(){
	int T=read();while(T--){
		For(i,1,n=read())a[i]=read();
		if(n&1){
			if(a[1]+a[2]){
				printf("%lld %lld %lld ",-a[3],-a[3],a[1]+a[2]);
			}else if(a[1]+a[3]){
				printf("%lld %lld %lld ",-a[2],a[1]+a[3],-a[2]);
			}else if(a[2]+a[3]){
				printf("%lld %lld %lld ",a[2]+a[3],-a[1],-a[1]);
			}
			solve(4);
		}else solve(1);
		puts("");
	}
	return 0;
}