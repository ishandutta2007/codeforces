#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#define LL long long
using namespace std;
const int N=5e5+10;
const int inf=1e9;
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
char s[N];
int l,r,u,d,a,b;
int check(int x,int y){
	return max(max(max(x-l,r-x),max(u-y,y-d)),max(b-(y-x),(y-x)-a));
}
int main(){
	scanf("%d",&n);
	int x,y,len;
	l=inf;r=-inf;
	d=inf;u=-inf;
	a=inf;b=-inf;
	for(int i=1;i<=n;++i){
		scanf("%s",s+1);
		len=strlen(s+1);
		x=0;
		for(int j=1;j<=len;++j) if(s[j]=='N') ++x;
		y=len-x;
		l=min(l,x);r=max(r,x);
		d=min(d,y);u=max(u,y);
		a=min(a,y-x);b=max(b,y-x);
	}
	x=l;y=u;
	for(int i=1;i<=5e5;++i){
		int j=(max(u,b+i)+min(d,a+i))/2;
		if(check(i,j)<check(x,y)) {x=i;y=j;}
	}
	cout<<check(x,y)<<endl;
	for(int i=1;i<=x;++i) putchar('N');
	for(int i=1;i<=y;++i) putchar('B');
	puts("");
	return 0;
}