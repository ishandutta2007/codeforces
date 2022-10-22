#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
char s[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
struct seg{int a,b,c,ab,bc,abc;}t[4*maxn];
void pushup(int k){
	int ls=k<<1,rs=k<<1|1;
	t[k].a=t[ls].a+t[rs].a,t[k].b=t[ls].b+t[rs].b,t[k].c=t[ls].c+t[rs].c;
	t[k].ab=min(t[ls].a+t[rs].ab,t[ls].ab+t[rs].b);
	t[k].bc=min(t[ls].b+t[rs].bc,t[ls].bc+t[rs].c);
	t[k].abc=min(min(t[ls].a+t[rs].abc,t[ls].abc+t[rs].c),t[ls].ab+t[rs].bc);
	return ;
}
void build(int k,int l,int r){
	if(l==r){
		if(s[l]=='a')t[k].a++;else if(s[l]=='b')t[k].b++;else t[k].c++;
		return ;
	}
	int mid=l+((r-l)>>1);
	build(k<<1,l,mid),build(k<<1|1,mid+1,r);
	pushup(k);
	return ;
}
void modify(int k,int l,int r,int x,int op){
	if(l==r){
		t[k]=(seg){0,0,0,0,0,0};
		if(op==1)t[k].a++;else if(op==2)t[k].b++;else t[k].c++;
		return ;
	}
	int mid=l+((r-l)>>1);
	if(x<=mid)modify(k<<1,l,mid,x,op);
	else modify(k<<1|1,mid+1,r,x,op);
	pushup(k);
	return ;
}
int main(){
	int n,q;
	n=read();q=read();
	scanf("%s",s+1);
	build(1,1,n);
	while(q--){
		int x;char c;
		x=read();scanf("%c",&c);
		modify(1,1,n,x,c-'a'+1);
		printf("%d\n",t[1].abc);
	}
    return 0;
}