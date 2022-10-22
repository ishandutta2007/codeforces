#include <bits/stdc++.h>
#define R register
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
int f[1<<22];
inline void fmax(int &x,int y){
	if(x<y)x=y;
	return ;
}
void sos(){
	int len=(1<<22);
	for(R int mid=1;mid<len;mid<<=1)
		for(R int j=0;j<len;j+=(mid<<1))
			for(R int k=0;k<mid;k++)
				fmax(f[j+k+mid],f[j+k]);
	return ;
}
int main(){
//    freopen("CF165E.in","r",stdin);
//    freopen("CF165E.out","w",stdout);
   	int n;
	n=read();
	memset(f,-1,sizeof(f));
	for(R int i=1;i<=n;i++){a[i]=read();f[a[i]]=a[i];}
	sos();
	int S=(1<<22)-1;
	for(R int i=1;i<=n;i++)printf("%d ",f[S^a[i]]);
    return 0;
}