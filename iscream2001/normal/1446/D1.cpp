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
int hed[N+N];
struct node{
	int id,v;
}e[N];
bool cmp(node x,node y){
	return x.v>y.v;
}
int main(){
	scanf("%d",&n);
	int flag=0;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		++e[a[i]].v;
		e[i].id=i;
	}
	sort(e+1,e+1+n,cmp);
	if(e[1].v==e[2].v){
		printf("%d\n",n);
		return 0;
	}
	int ans=0;
	int now;
	for(int i=2;i<=min(n,100);++i){
		for(int j=-n;j<=n;++j) hed[j+n]=-1;
		hed[0+n]=0;
		now=0;
		for(int j=1;j<=n;++j){
			if(a[j]==e[1].id) ++now;
			else if(a[j]==e[i].id) --now;
			hed[now+n]=j;
		}
		now=0;ans=max(ans,hed[0+n]-0);
		for(int j=1;j<=n;++j){
			if(a[j]==e[1].id) ++now;
			else if(a[j]==e[i].id) --now;
			ans=max(ans,hed[now+n]-j);
		}
	}
	printf("%d\n",ans);
	return 0;
}