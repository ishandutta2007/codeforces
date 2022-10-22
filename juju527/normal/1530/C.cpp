#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int suma[maxn],sumb[maxn];
int a[maxn],b[maxn];
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
        int n;
        n=read();
        suma[n+1]=sumb[n+1]=0;
        for(int i=1;i<=n;i++)a[i]=read();sort(a+1,a+n+1);
        for(int i=n;i>=0;i--)suma[i]=suma[i+1]+a[i];
        for(int i=1;i<=n;i++)b[i]=read();sort(b+1,b+n+1);
        for(int i=n;i>=0;i--)sumb[i]=sumb[i+1]+b[i];
        if(suma[n-(n-(n/4))+1]>=sumb[n-(n-(n/4))+1]){puts("0");continue;}
        int res=0;
        for(int i=1;i<=n;i++){
            int k=(n+i)-((n+i)/4);
            if(k>=i){
                if(suma[n-(k-i)+1]+i*100>=sumb[max(n-k+1,0)]){res=i;break;}
            }
            else{
                if(k*100>=sumb[max(n-k+1,0)]){res=i;break;}
            }
        }
        printf("%d\n",res);
    }
    return 0;
}