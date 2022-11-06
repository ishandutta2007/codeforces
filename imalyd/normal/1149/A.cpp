#include<bits/stdc++.h>
using namespace std;
#define ll long long
namespace io{
    const int l=1<<19;
    char buf[l],*s,*t,c;
    char gc(){
        if(s==t){
            t=(s=buf)+fread(buf,1,l,stdin);
            return s==t?EOF:*s++;
        }
        return *s++;
    }
    template<class I>void gi(I &x){
        x=0;c=gc();while(c<'0'||c>'9')c=gc();
        while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=gc();}
    }
};
using io::gi;

const int N=400005;

int n,m,vis[N],a,b,t;

int main(){
	scanf("%d",&n);m=n<<1;
	for(int i=2;i<=m;i++)if(!vis[i])for(int j=i<<1;j<=m;j+=i)vis[j]=1;
	for(int i=2;i<=m;i++)vis[i]^=1;
	for(int i=1;i<=n;i++){
		int x;scanf("%d",&x);
		if(x==1)++a;else ++b;
	}
	while(a&&b){
		if(vis[t+1]){
			--a;
			++t;
			printf("1 ");
		}else{
			--b;
			t+=2;
			printf("2 ");
		}
	}
	while(a--){++t ;printf("1 ");}
	while(b--){t+=2;printf("2 ");}
	return 0;
}