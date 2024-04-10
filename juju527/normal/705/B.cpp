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
//    freopen("CF705B.in","r",stdin);
//    freopen("CF705B.out","w",stdout);
 	int n;
	n=read();
	int s=0;
	for(int i=1;i<=n;i++){
		int a=(read()&1)^1;
		s^=a;
		if(s>0)printf("1\n");
		else printf("2\n");
	}
    return 0;
}