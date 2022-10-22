#include <bits/stdc++.h>
#define dig(a,b) (a/p[b]%10)
using namespace std;
typedef long long ll;
ll dp[512][19][2520],p[19];
bitset<2520> use[512];
vector<int> uv[512];
void setup(int msk){
    int l=1,i,j,k;
    for(i=1;i<=9;i++)if((msk>>i-1)&1)l=l*i/__gcd(l,i);
    for(i=0;i<2520;i+=l)use[msk][i]=1;
    for(i=0;i<512;i++){
        if((msk&i)==msk)use[msk]&=use[i].flip(),use[i].flip();
    }
    dp[msk][0][0]=1;
    for(i=1;i<19;i++){
        for(j=0;j<=9;j++)if(j==0||((msk>>j-1)&1)){
            for(k=0;k<2520;k++){
                dp[msk][i][(k+j*p[i-1])%2520]+=dp[msk][i-1][k];
            }
        }
    }
    for(i=0;i<2520;i+=l)if(use[msk][i])uv[msk].push_back(i);
}
ll doshit(ll x,int msk){
    int l=1,i,j,k;
    ll cum=0,ans=0;
    for(i=18;i>=0;i--){
        for(j=0;j<x/p[i]%10;j++)if(j==0||((msk>>j-1)&1)){
            for(int k:uv[msk]){
                ans+=dp[msk][i][((k-j*p[i]-cum)%2520+2520)%2520];
            }
        }
        if(j==0||((msk>>j-1)&1)){
            cum+=x/p[i]%10*p[i];
            cum%=2520;
        }
        else break;
    }
    return ans;
}

ll solve(ll x){
    x++;
    int i;
    ll ans=0;
    vector<int> v;
    for(i=1;i<512;i++){
        ll inc=doshit(x,i);
        ans+=inc;
        if(inc)v.push_back(i);
    }
    return ans;
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int i;
    p[0]=1;
    for(i=1;i<19;i++)p[i]=p[i-1]*10;
    for(i=511;i;i--)setup(i);
    int tc;
    cin>>tc;
    //use[1].set();
    while(tc--){
        ll l,r;
        cin>>l>>r;
        cout<<solve(r)-solve(l-1)<<endl;
    }
}