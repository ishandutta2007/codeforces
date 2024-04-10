#include <bits/stdc++.h>
using namespace std;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int main(){
//    freopen("CF739A.in","r",stdin);
//    freopen("CF739A.out","w",stdout);
    int n,m,ans;
	n=read();m=read();
	ans=n;
	for(int i=1;i<=m;i++){
		int l,r;
		l=read();r=read();
		ans=min(ans,r-l+1);
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)printf("%d ",i%ans);
    return 0;
}