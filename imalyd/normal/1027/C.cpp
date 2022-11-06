//Problem C
#include<bits/stdc++.h>
using namespace std;

int t,n,a[1000005],b[1000005],s,v,u;
void rd(int &a){
    a=0;char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while( isdigit(ch))a=(a<<1)+(a<<3)+(ch^48),ch=getchar();
}
long long cal(int a,int b,int c,int d){
    return 1ll*(a+b)*(a+b)*c*d;
}
void op(int a){
    if(9<a)op(a/10);
    putchar((a%10)|48);
}
void oop(int a,char ch){
    op(a),putchar(ch);
}
int main(){
    rd(t);
    while(t--){
        rd(n),s=0;
        for(int i=1;i<=n;i++)rd(a[i]);
        sort(a+1,a+n+1);
        v=u=0;
        int f=0;
        for(int i=1,j=1;i<=n;i=j){
            while(j<=n&&a[i]==a[j])++j;
            int x=(j-i)>>1;
            while(x--)b[++s]=a[i];
        }
        for(int i=1;i<s;i++){
            int V=b[i],U=b[i+1];
            if(!v)v=V,u=U;else
                if(cal(V,U,v,u)<cal(v,u,V,U))v=V,u=U;
        }
        oop(v,' ');
        oop(v,' ');
        oop(u,' ');
        oop(u,'\n');
    }
    return 0;
}