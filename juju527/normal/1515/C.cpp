#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
struct seq{
    int id,data;
    bool operator <(seq i)const{
        return data<i.data;
    }
}a[maxn];
int h[maxn];
int bl[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
struct node{
    int id,data;
    bool operator <(node i)const{
        return data>i.data;
    }
};
priority_queue<node>q;
int main(){
    int T;
    T=read();
    while(T--){
        int n,m,x;
        n=read();m=read();x=read();
        for(int i=1;i<=n;i++)h[i]=read(),a[i]=(seq){i,h[i]};
        sort(h+1,h+n+1);
        sort(a+1,a+n+1);
        for(int i=n-m+1;i<=n;i++)q.push((node){n-i+1,h[i]}),bl[a[i].id]=n-i+1;
        for(int i=n-m;i>=1;i--){
            int v=q.top().data,id=q.top().id;
            bl[a[i].id]=id;
            q.pop();
            q.push((node){id,v+h[i]});
        }
        int mn=q.top().data,mx=0;
        while(!q.empty())mx=q.top().data,q.pop();
        if(mx-mn<=x){
            puts("YES");
            for(int i=1;i<=n;i++)printf("%d ",bl[i]);
            puts("");
        }
        else puts("NO");
    }
    return 0;
}