#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int a[maxn];
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
        int n,w=0;
        n=read();
        for(int i=1;i<=n;i++)a[i]=read(),w=max(w,a[i]);
        if(n==1){puts("0");continue;}
        int c=0,m=0;
        bool flag=0;
        for(int i=1;i<n;i++)if(a[i]<=a[i+1]){c=a[i+1]-a[i];flag=1;break;}
        if(!flag){
            int pre=a[2]-a[1];
            for(int i=2;i<=n;i++)if(a[i]-a[i-1]!=pre){flag=1;break;}
            if(flag){puts("-1");continue;}
            else{puts("0");continue;}
        }
        for(int i=1;i<n;i++){
            if(a[i]<=a[i+1]&&a[i+1]-a[i]!=c){flag=0;break;}
            if(a[i]>a[i+1]){
                if(!m)m=c-a[i+1]+a[i];
                else if(m!=c-a[i+1]+a[i]){flag=0;break;}
            }
        }
        if(m&&m<=w)flag=0;
        if(!flag){puts("-1");continue;}
        if(!m)puts("0");
        else printf("%d %d\n",m,c);
    }
    return 0;
}