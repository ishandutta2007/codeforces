#include <bits/stdc++.h>
using namespace std;
const int maxn=2005,maxm=2005,maxs=1e6+5;
struct point{
	int x,y;
}a[maxn],b[maxm];
int n,m,w;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int h[maxs];
int lowbit(int x){
	return x&-x;
}
void update(int x,int val){
	while(x<=w+1){
		h[x]=max(h[x],val);
		x+=lowbit(x);
	}
	return ;
}
int query(int x){
	int ans=0;
	while(x){
		ans=max(ans,h[x]);
		x-=lowbit(x);
	}
	return ans;
}
int main(){
//    freopen("CF1408D.in","r",stdin);
//    freopen("CF1408D.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		a[i].x=read();
		a[i].y=read();
		w=max(w,a[i].x);
	}
	for(int i=1;i<=m;i++){
		b[i].x=read();
		b[i].y=read();
		w=max(w,b[i].x);
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[j].x>b[i].x)continue;
			update(w-(b[i].x-a[j].x)+1,max(0,b[i].y-a[j].y+1));
		}
	}
	int ans=0x3f3f3f3f;
	for(int i=1;i<=w+2;i++){
		ans=min(ans,i-1+query(w+1-i+1));
//		cout<<i-1<<" "<<query(w+1-i+1)<<endl;
	}
    printf("%d\n",ans);
	return 0;
}