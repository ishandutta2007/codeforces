#include <bits/stdc++.h>
using namespace std;
inline int read(){
    int X=0,w=1; char ch=0;
    while(ch<'0' || ch>'9') {if(ch=='-') w=-1;ch=getchar();}
    while(ch>='0' && ch<='9') X=(X<<3)+(X<<1)+ch-'0',ch=getchar();
    return X*w;
}
double f[2],c[2],s;
int n,i=0;
int main(){
    n=read();
    for(int j=1;j<=n;j++){
        cin>>s;
        c[i^1]=(c[i]+1)*s;
        f[i^1]=f[i]+2*c[i]*s+s;
        i^=1;
    }
    printf("%.10lf",f[i]);
    //printf("%.10Lf",f[i]);
}