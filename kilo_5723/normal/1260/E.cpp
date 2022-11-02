#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
typedef long long ll;
const int maxn=1<<18;
ll a[maxn];
priority_queue<int,vector<int>,greater<int> > que;
int main(){
    int i,n,m;
    bool flg;
    ll ans;
    scanf("%d",&n);
    for (i=0;i<n;i++) scanf("%lld",&a[i]);
    m=n; flg=false; ans=0;
    while (true){
        for (i=n-1;i<m;i++){
            if (a[i]==-1){
                flg=true; break;
            }
            que.push(a[i]);
        }
        if (flg) break;
        ans+=que.top(); que.pop();
        m=n-1; n>>=1;
    }
    printf("%lld\n",ans);
    return 0;
}