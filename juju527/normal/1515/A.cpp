#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int w[maxn];
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
        int n,x,sum=0;
        n=read();x=read();
        for(int i=1;i<=n;i++)w[i]=read(),sum+=w[i];
        sort(w+1,w+n+1);
        if(sum==x)puts("NO");
        else{
            puts("YES");
            sum=0;
            for(int i=1;i<=n;i++){
                sum+=w[i];
                if(sum==x){
                    swap(w[i],w[n]);
                    sum+=w[i]-w[n];
                    break;
                }
            }
            for(int i=1;i<=n;i++)printf("%d ",w[i]);
            puts("");
        }
    }
    return 0;
}