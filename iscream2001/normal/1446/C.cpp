#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N=3e5+10;
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
int b[50];
int ask(int l,int r,int k){
	if(k>0){
		int x=0;
		for(int i=l;i<=r;++i){
			if((a[i]&b[k])==0) ++x;
		}
		if(x==r-l+1||x==0) return ask(l,r,k-1);
		return max(ask(l,l+x-1,k-1),ask(l+x,r,k-1))+1;
	}
	int x=0;
	for(int i=l;i<=r;++i){
		if((a[i]&b[k])==0) ++x;
	}
	if(x==r-l+1||x==0) return 1;
	return 2;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	b[0]=1;
	for(int i=1;i<=30;++i) b[i]=b[i-1]<<1;
	printf("%d\n",n-ask(1,n,30));
	return 0;
}