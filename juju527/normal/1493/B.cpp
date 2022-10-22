#include<bits/stdc++.h>
using namespace std;
char chg[10]={'0','1','5','b','b','2','b','b','8','b'};
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int main(){
    int T;
    T=read();
    while(T--){
        int h,m,u,v,a,b,c,d,A,B,C,D;
        h=read();m=read();
        u=read();v=read();
        while(1){
            a=u/10;b=u%10;c=v/10;d=v%10;
            if(!(chg[a]=='b'||chg[b]=='b'||chg[c]=='b'||chg[d]=='b')){
                A=chg[d]-'0';B=chg[c]-'0';C=chg[b]-'0';D=chg[a]-'0';
                if(A*10+B<h&&C*10+D<m){
                    printf("%d%d:%d%d\n",a,b,c,d);
                    break;
                }
            }
            v++;
            if(v==m){
                v=0,u++;
                if(u==h)u=0;
            }
        }
    }
    return 0;
}