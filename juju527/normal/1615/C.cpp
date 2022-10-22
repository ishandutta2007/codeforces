#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
char a[maxn],b[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int main(){
	int T;
	T=read();
	while(T--){
		int n;
		n=read();
		scanf("%s",a+1);scanf("%s",b+1);
		int x=0,y=0;
		for(int i=1;i<=n;i++)x+=(a[i]=='1'),y+=(b[i]=='1');
		if(y!=x&&y!=n-x+1){puts("-1");continue;}
		bool tag=0;
		int res=1e9;
		if(y==x){
			int cur=0;
			for(int i=1;i<=n;i++)if(a[i]!=b[i])cur++;
			res=min(res,cur);
		}
		if(y==n-x+1){
			int cur=0;
			for(int i=1;i<=n;i++)if(a[i]==b[i])cur++;
			res=min(res,cur);
		}
		printf("%d\n",res);
	}
    return 0;
}