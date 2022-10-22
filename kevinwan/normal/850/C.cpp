#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
typedef long long ll;
const int mn=2e5+10;
int thres=1<<17;
map<int,int>dp;
map<int,int>m;
int solve(int x){
    bitset<32>num;
    if(x&1)x--;
    if(x==0)return 0;
    if(dp.count(x))return dp[x];
    for(int j=1;1LL<<j<=x;j++){
        num[solve((x>>j)|(x&((1<<j)-1)))]=1;
    }
    int ans=-1;
    for(int j=0;1LL<<j<=x;j++)if(!num[j]){
        ans=j;
        break;
    }
    num.reset();
    assert(ans>=0);
    return dp[x]=ans;
}
int main(){
    int n;
    scanf("%d",&n);
    solve(323425);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        for(int j=2;j*j<=x;j++){
            if(x%j==0){
                int num=0;
                while(x%j==0){
                    x/=j;
                    num++;
                }
                m[j]|=1<<num;
            }
        }
        if(x!=1)m[x]|=2;
    }
    int ans=0;
    for(pii p:m)ans^=solve(p.second);
    if(ans)printf("Mojtaba");
    else printf("Arpa");
}