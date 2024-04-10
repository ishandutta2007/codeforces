#include <bits/stdc++.h>
using namespace std;
const int maxm=1e5+5;
int n,m,w;
int a[maxm],pre[maxm],suf[maxm];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int lowbit[maxm];
int t[maxm];
void update(int x,int val){
	while(x<=w){
		t[x]=max(t[x],val);
		x+=lowbit[x];
	}
	return ;
}
int query(int x){
	int ans=0;
	while(x){
		ans=max(ans,t[x]);
		x-=lowbit[x];
	}
	return ans;
}
int main(){
//    freopen("CF930C.in","r",stdin);
//    freopen("CF930C.out","w",stdout);
    n=read();m=read();
	for(int i=1;i<=n;i++){
		int l,r;
		l=read();r=read();
		a[l]++;a[r+1]--;
	}
	a[0]++;
	for(int i=1;i<=m;i++){
		a[i]+=a[i-1];
		w=max(w,a[i]);
	}
	for(int i=1;i<=w;i++)lowbit[i]=(i&-i);
	for(int i=1;i<=m;i++){
		pre[i]=query(a[i])+1;
		update(a[i],pre[i]);
	}
	for(int i=0;i<=w;i++)t[i]=0;
	for(int i=m;i>=1;i--){
		suf[i]=query(a[i])+1;
		update(a[i],suf[i]);
	}
	int ans=0;
	for(int i=1;i<=m;i++)ans=max(ans,pre[i]+suf[i]-1);
    printf("%d\n",ans);
	return 0;
}