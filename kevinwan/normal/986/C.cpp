#include<bits/stdc++.h>
using namespace std;
const int mn=1<<23;
int a[mn];
bool vis[mn];
int n;
void dfs(int xx){
    //cout<<x;
    vis[xx]=1;
    stack<int>s;
    s.push(xx);
    while(s.size()){
        int x=s.top();
        s.pop();
        if(x<1<<n){
            for(int i=0;i<n;i++)if(!((x>>i)&1))if(!vis[x+(1<<i)])s.push(x+(1<<i)),vis[x+(1<<i)]=1;
            if(!vis[(1<<n)-1-x+(1<<n)])s.push((1<<n)-1-x+(1<<n)),vis[(1<<n)-1-x+(1<<n)]=1;
        }
        else if(!vis[x-(1<<n)])s.push(x-(1<<n)),vis[x-(1<<n)]=1;
    }
}
int main(){
    int m;
    scanf("%d%d",&n,&m);
    //cout<<"HAIL";
    //cout<<"HAIL";
    for(int i=1<<n;i<1<<n+1;i++)vis[i]=1;
    for(int i=0;i<m;i++)scanf("%d",a+i),vis[(1<<n)+a[i]]=0;
    int num=0;
    for(int i=0;i<m;i++)if(!vis[a[i]+(1<<n)])dfs(a[i]+(1<<n)),num++;
    printf("%d",num);
}