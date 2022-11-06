//Problem D
#include<bits/stdc++.h>
using namespace std;

int n,a[200005],b[200005],vis[200005],u,c;
void rd(int &a){
    a=0;char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while( isdigit(ch))a=(a<<1)+(a<<3)+(ch^48),ch=getchar();
}
int main(){
    rd(n);
    for(int i=1;i<=n;i++)rd(b[i]);
    for(int i=1;i<=n;i++)rd(a[i]);
    for(int i=1;i<=n;i++){
        a[0]=i;int v=0;++c;
        while(1){
            v=a[v];//printf("vis %d %d\n",v,c);
            if(vis[v]&&vis[v]!=c)break;
            if(vis[v]==c){
                int mn=b[v];//printf("qmin %d\n",v);
                for(int i=a[v];i!=v;i=a[i])mn=min(mn,b[i]);//printf("qmin %d\n",i);
                u+=mn;
                break;
            }
            vis[v]=c;
        }
    }
    printf("%d",u);
    return 0;
}