#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=100010;
int i,j,k,n,m,a[maxn];ll b[40],ans;
int main(){
	int T=read();
	while(T--){
		memset(b,0,sizeof(b));ans=0;
		n=read();
		for(i=1;i<=n;i++)a[i]=read();
		for(i=1;i<=n;i++){
			int o=0;
			while(a[i]){
				a[i]/=2;
				o++;
			}b[o]++;
		}
		for(i=0;i<=35;i++)ans+=(b[i]-1)*b[i]/2;
		printf("%I64d\n",ans);
	}
	return 0;
}