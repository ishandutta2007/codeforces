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
int gcd(int x,int y){
    return y==0?x:gcd(y,x%y);
}
struct node{
    int x,y;
};
queue<node>q;
set<int>s;
bool ban[maxn];
int ans[maxn];
int main(){
    int T;
    T=read();
    while(T--){
        int n;
        n=read();
        for(int i=1;i<=n;i++)a[i]=read();
        if(n==1){
            if(a[1]>1)puts("0");
            else puts("1 1");
            continue;
        }
        s.clear();
        for(int i=1;i<n;i++)q.push((node){i,i+1}),s.insert(i);
        q.push((node){n,1});s.insert(n);
        int len=0;
        for(int i=1;i<=n;i++)ban[i]=0;
        while(!q.empty()){
            int x=q.front().x,y=q.front().y;
            q.pop();
            if(ban[x])continue;
            if(gcd(a[x],a[y])==1){
                s.erase(y);
                ban[y]=1;
                ans[++len]=y;
                int v;
                if(s.upper_bound(y)==s.end())v=*s.lower_bound(1);
                else v=*s.upper_bound(y);
                q.push((node){x,v});
            }
        }
        printf("%d ",len);
        for(int i=1;i<=len;i++)printf("%d ",ans[i]);
        puts("");
    }
    return 0;
}