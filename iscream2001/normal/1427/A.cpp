#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e6+10;
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
int n;
int a[N];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int x=0,y=0;
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		for(int i=1;i<=n;++i){
			if(a[i]>0) x+=a[i];
			else y-=a[i];
		}
		if(x==y) puts("NO");
		else{
			puts("YES");
			if(x>y) {
				for(int i=n;i>=1;--i) printf("%d ",a[i]);
			}
			else {
				for(int i=1;i<=n;++i) printf("%d ",a[i]);
			}
			puts("");
		}
	}
	return 0;
}