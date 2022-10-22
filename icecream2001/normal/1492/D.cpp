#include <bits/stdc++.h>
#define LL long long
#define LD long double
using namespace std;
const LL P=998244353;
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
void pls(LL &x,LL y){
    x+=y;if(x>=P)x-=P;
}
int a,b,k,n;
int A[N],B[N];
void MAIN(){
    scanf("%d%d%d",&a,&b,&k);
    n=a+b;
    if(k==0){
    	puts("Yes");
    	for(int i=1;i<=b;++i) putchar('1');
    	for(int i=1;i<=a;++i) putchar('0');
    	puts("");
    	for(int i=1;i<=b;++i) putchar('1');
    	for(int i=1;i<=a;++i) putchar('0');
    	puts("");
    	return;
	}
	if(k==n||k==n-1||a==0||b==1){
		puts("No");
		return;
	}
	b-=2;a--;
	A[1]=B[1]=1;
	A[2]=1;B[2]=0;
	A[2+k]=0;
	B[2+k]=1;
	for(int i=3;i<2+k;++i){
		if(a>0){
			A[i]=B[i]=0;
			--a;
		}
		else{
			A[i]=B[i]=1;
			--b;
		}
	}
	for(int i=3+k;i<=n;++i){
		if(a>0){
			A[i]=B[i]=0;
			--a;
		}
		else{
			A[i]=B[i]=1;
			--b;
		}
	}
	puts("Yes");
    for(int i=1;i<=n;++i) printf("%d",A[i]);puts("");
    for(int i=1;i<=n;++i) printf("%d",B[i]);puts("");
    return;
}

int main(){
    int ttt=1;
    while(ttt--) MAIN();
    return 0;
}