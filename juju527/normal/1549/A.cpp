#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
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
        int p;
        p=read();
        int lim=min(1000,p);
        for(int i=0;i<=lim;i++)a[i]=0;
        for(int i=2;i<=lim;i++){
            int v=p%i;
            if(a[v]){
                printf("%d %d\n",a[v],i);
                break;
            }
            a[v]=i;
        }
    }
    return 0;
}