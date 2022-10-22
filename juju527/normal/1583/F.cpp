#include <bits/stdc++.h>
#define ll long long
using namespace std;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int main(){
	int n,k;
	n=read();k=read();
	int res=1;
	for(int v=k;;v*=k,res++)if(v>=n)break;
	printf("%d\n",res);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int w=1;
			for(int v=k;;v*=k,w++)
				if((i-1)/v==(j-1)/v){printf("%d ",w);break;}
		}
	}
    return 0;
}