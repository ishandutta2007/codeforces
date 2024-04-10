#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N=3e5+10;
const int INF=1e9;
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
int n,K;
struct node{
	int x,y;
}a[N];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&K);
		for(int i=1;i<=n;++i){
			scanf("%d%d",&a[i].x,&a[i].y);
		}
		bool flag=0,v;
		for(int i=1;i<=n&&flag==0;++i){
			v=0;
			for(int j=1;j<=n;++j){
				if(abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y)>K) v=1;
			}
			if(v==0) flag=1;
		}
		if(flag) puts("1");
		else puts("-1");
	}
	return 0;
}