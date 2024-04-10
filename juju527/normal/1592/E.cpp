#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=(1<<20)+5,w=(1<<20);
int a[maxn];
int pre0[maxn],pre1[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int main(){
	int n;
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	int res=0;
	for(int k=0;k<20;k++){
		int val=0;
		for(int i=0;i<=w;i++)pre0[i]=pre1[i]=-1;
		int lst=-1;
		pre0[0]=0;
		for(int i=1;i<=n;i++){
			val=val^(a[i]&((1<<20)-(1<<k)));
			if((a[i]>>k)&1){if(lst==-1)lst=i;}
			else lst=-1;
			if(i&1){
				if(lst!=-1){
					if(pre1[val]<lst-1)pre1[val]=i;
					res=max(res,i-pre1[val]);
				}
				else pre1[val]=i;
			}
			else{
				if(lst!=-1){
					if(pre0[val]<lst-1)pre0[val]=i;
					res=max(res,i-pre0[val]);
				}
				else pre0[val]=i;
			}
		}
	}
	printf("%d\n",res);
    return 0;
}