#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int a[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int mx[(1<<21)],cx[(1<<21)];
inline void update(int k,int x){
	if(mx[k]<x){cx[k]=mx[k];mx[k]=x;}
	else if(mx[k]==x)cx[k]=x;
	else cx[k]=max(cx[k],x);
	return ;
}
void sos(int len){
	for(int i=0;i<21;i++)
		for(int j=0;j<len;j++)
			if(!(j&(1<<i))){
				update(j,mx[j^(1<<i)]);
				update(j,cx[j^(1<<i)]);
			}
	return ;
}
int main(){
//    freopen("CF1208F.in","r",stdin);
//    freopen("CF1208F.out","w",stdout);
   	int n;
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		update(a[i],i);
	}
	sos(1<<21);
//	for(int i=1;i<(1<<21);i++)cout<<i<<" "<<mx[i]<<" "<<cx[i]<<endl;
	int S=(1<<21)-1,ans=0;
	for(int i=1;i<=n-2;i++){
		int c=S^a[i];
		int s=0;
		for(int j=21;j>=0;j--){
			if(!((c>>j)&1))continue;
			s+=(1<<j);
			if(cx[s]<=i)s-=(1<<j);
		}
		ans=max(ans,a[i]+s);
	}
	printf("%d\n",ans);
    return 0;
}