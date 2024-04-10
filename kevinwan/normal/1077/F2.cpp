#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=5e3+10;
ll dp[mn];
int n;
template<typename T>
struct mqueue{
    stack<pair<T,T>>a,b;
    inline void move_over(){
        while(a.size()){
            b.push({a.top().first,max(a.top().first,b.size()?b.top().second:a.top().first)});
            a.pop();
        }
    }
    T front(){
        if(b.size())return b.top().first;
        else{
            move_over();
            return b.top().first;
        }
    }
    T biggest(){
        if(b.size()&&a.size())return max(a.top().second,b.top().second);
        else if(b.size())return b.top().second;
        else if(a.size())return a.top().second;
        else return 0x8000000000000000;
    }
    void pop(){
        if(b.size())b.pop();
        else{
            move_over();
            b.pop();
        }
    }
    void push(T x){
        a.push({x,max(x,a.size()?a.top().second:x)});
    }
    int size(){
        return a.size()+b.size();
    }
};
ll v[mn];
mqueue<ll> q[mn];
int main()
{
    int k,x,i,j;
    scanf("%d%d%d",&n,&k,&x);
    memset(dp,0xc0,sizeof(dp));
    dp[0]=0;
    q[0].push(0);
    for(i=1;i<=n;i++)scanf("%lld",v+i);
    for(i=1;i<=n;i++){
        dp[0]=0xc0c0c0c0c0c0c0c0;
        for(j=1;j<=x;j++){
            dp[j]=q[j-1].biggest()+v[i];
        }
        for(j=0;j<=x;j++){
            q[j].push(dp[j]);
            if(q[j].size()>k)q[j].pop();
        }
    }
    ll ans=q[x].biggest();
    if(ans<0)printf("-1");
    else printf("%lld",ans);
}