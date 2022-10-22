#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=3e5+5;
int n;
char s[500005];
int a[maxn],b[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int x,y;
bool chk(int d){
	int l1=0,r1=1e9,l2=0,r2=1e9,l3=-1e9,r3=1e9;
	for(int i=1;i<=n;i++){
		l1=max(l1,a[i]-d),r1=min(r1,a[i]+d);
		l2=max(l2,b[i]-d),r2=min(r2,b[i]+d);
		l3=max(l3,a[i]-b[i]-d),r3=min(r3,a[i]-b[i]+d);
	}
	if(l1>r1||l2>r2||l3>r3||r1-l2<l3||l1-r2>r3)return 0;
	x=min(r1,r2+r3);
	y=min(x-l3,r2);
	return 1;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		int len=strlen(s+1),x=0,y=0;
		for(int i=1;i<=len;i++)if(s[i]=='B')x++;else y++;
		a[i]=x,b[i]=y;
	}
	int l=-1,r=5e5;
	while(l+1<r){
		int mid=l+((r-l)>>1);
		if(chk(mid))r=mid;
		else l=mid;
	}
	printf("%d\n",r);
	for(int i=1;i<=x;i++)putchar('B');
	for(int i=1;i<=y;i++)putchar('N');
	puts("");
    return 0;
}