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
int n,m;
int a[N];

int c[N];
int ans[N];
void ask(int l,int r,int x,int y){
	if(l>r) return;
	if(c[x]==0) return;
	ans[y]=1;
	if(c[x]>1) return;
	if(a[l]==x) ask(l+1,r,x+1,y-1);
	else if(a[r]==x) ask(l,r-1,x+1,y-1);
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) {
			c[i]=0;
			ans[i]=0;
		}
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			++c[a[i]];
		}
		ans[1]=1;
		for(int i=1;i<=n;++i){
			if(c[i]!=1) ans[1]=0;
		}
		ask(1,n,1,n);
		for(int i=1;i<=n;++i) printf("%d",ans[i]);puts("");
	}
	return 0;
}