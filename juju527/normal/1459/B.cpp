#include<bits/stdc++.h>
using namespace std;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int main(){
    int n,ans=0;
    n=read();
    int p=(n+1)/2;
    for(int i=-p;i<=p;i++){
        for(int j=-p;j<=p;j++){
            int kx=abs(i),ky=abs(j);
            if(kx<ky)swap(kx,ky);
            int s1,s2;
            if((kx-ky)&1)s1=2*kx-1,s2=2*kx+1;
            else s1=2*kx,s2=2*kx;
            if((n%4)==s1%4&&s1<=n||(n%4)==s2%4&&s2<=n)ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}