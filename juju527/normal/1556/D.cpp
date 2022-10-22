#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
int a[maxn],b[maxn];
bool vis[maxn];
int val;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int main(){
    int n,k;
    n=read();k=read();
    for(int i=2;i<=n;i++){
        printf("or 1 %d\n",i);fflush(stdout);a[i]=read();
        printf("and 1 %d\n",i);fflush(stdout);b[i]=read();
    }
    printf("or 2 3\n");fflush(stdout);val=read();
    int res=0;
    for(int c=29;c>=0;c--){
        int x=-1,num=0;
        for(int j=2;j<=n;j++)if(((a[j]>>c)&1)==((b[j]>>c)&1)){x=(a[j]>>c)&1;break;}
        if(x==-1){
            if((val>>c)&1)x=0;
            else x=1;
        }
        if(!x&&!vis[1])num++;
        for(int j=2;j<=n;j++){
            if(vis[j])continue;
            if((x&&!((b[j]>>c)&1))||(!x&&!((a[j]>>c)&1)))num++;
        }
        if(num>=k){
            for(int j=2;j<=n;j++)if(!((x&&!((b[j]>>c)&1))||(!x&&!((a[j]>>c)&1))))vis[j]=1;
            if(x)vis[1]=1;
        }
        else{
            k-=num;
            for(int j=2;j<=n;j++)if((x&&!((b[j]>>c)&1))||(!x&&!((a[j]>>c)&1)))vis[j]=1;
            if(!x)vis[1]=1;
            res|=(1<<c);
        }
    }
    printf("finish %d\n",res);fflush(stdout);
    return 0;
}