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
LL p,a,b,c,v,A,B,C; 
void MAIN(){
    cin>>p>>a>>b>>c;
    v=p/a;A=a*v;if(A<p)A+=a;
    v=p/b;B=b*v;if(B<p)B+=b;
    v=p/c;C=c*v;if(C<p)C+=c;
    printf("%lld\n",min(A,min(B,C))-p);
    return;
}

int main(){
    int ttt=read();
    while(ttt--) MAIN();
    return 0;
}