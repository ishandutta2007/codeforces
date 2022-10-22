#include<bits/stdc++.h>
using namespace std;
const int maxnm=300*300+5;
struct node{
    int id,v;
    bool operator <(node i)const{return v==i.v?id>i.id:v<i.v;}
}a[maxnm];
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
        int n,m;
        n=read();m=read();
        for(int i=1;i<=n*m;i++)a[i]=(node){i,read()};
        sort(a+1,a+n*m+1);
        int res=0;
        for(int i=1;i<=m;i++)
            for(int j=1;j<i;j++)
                if(a[j].id<a[i].id)res++;
        printf("%d\n",res);
    }
    return 0;
}