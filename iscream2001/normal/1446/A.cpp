#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N=3e5+10;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void print(LL x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
int n;
LL W;
LL a[N];
int tp;
int q[N];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%I64d",&n,&W);
		int j=0;
		for(int i=1;i<=n;++i){
			scanf("%I64d",&a[i]);
		}
		for(int i=1;i<=n;++i){
			if(a[i]+a[i]>=W&&a[i]<=W){
				j=i;break;
			}
		}
		if(j>0){
			puts("1");
			printf("%d\n",j);
			continue;
		}
		LL sum=0;tp=0;
		for(j=1;j<=n;++j){
			if(a[j]<=W) {
				sum+=a[j];
				q[++tp]=j;
			}
			if(sum+sum>=W&&sum<=W){
				break;
			}
		}
		if(j<=n){
			printf("%d\n",tp);
			for(int i=1;i<=tp;++i) printf("%d ",q[i]);
			puts("");
			continue;
		}
		puts("-1");
	}
	return 0;
}