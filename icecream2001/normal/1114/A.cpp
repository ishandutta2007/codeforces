#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<cstring>
#include<map>
#define LL long long
using namespace std;

inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void Out(int x){
	if(x>9) Out(x/10);
	putchar('0'+x%10);
}
int gcd(int x,int y){
	if(!y) return x;
	return gcd(y,x%y);
}
LL qpow(LL x,LL y,LL P){
	LL re=1;
	while(y){
		if(y&1) re=re*x%P;
		x=x*x%P;y>>=1;
	}
	return re;
}
const int N=2e5+10;
const LL P=1e9+7;
int a,b,c,x,y,z;
int main(){
	cin>>x>>y>>z>>a>>b>>c;
	if(a<x){puts("NO");return 0;}
	b+=(a-x);
	if(b<y){puts("NO");return 0;}
	c+=(b-y);
	if(c<z){puts("NO");return 0;}
	puts("YES");return 0;
} 
/*

*/