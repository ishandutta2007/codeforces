#include <bits/stdc++.h>
using namespace std;
typedef short ll;
typedef long double ld;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
#define exp fgfdgd

const ll DIM = 257;
const ll M = 120;
const ll base = 57;
const ll INF = 32000;
const ll MAXN = 250;
ll dp[M][DIM][DIM],olddp[M][DIM][DIM];
ll gi(char ch){
    return ch-'0';
}
int main()
{


    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string n;
    cin>>n;
    reverse(n.begin(),n.end());
    n+='0';
    for(ll carry = 0;carry<=base*2+1;++carry){
        for(ll d1 = 0;d1<=MAXN;++d1){
            for(ll d2 = 0;d2<=MAXN;++d2){
                olddp[carry][d1][d2] = dp[carry][d1][d2] = INF;
                if (carry==base)olddp[carry][d1][d2] = 0;
            }
        }
    }
    for(char to:n){
        ll num = gi(to);
        for(ll carry = -base;carry<=base;++carry){
            for(ll d1 = MAXN;d1>=0;--d1){
                for(ll d2 = MAXN;d2>=0;--d2){
                    if (d1==MAXN)olddp[base+carry][d1+1][d2] = INF;
                    if (d2==MAXN)olddp[base+carry][d1][d2+1] = INF;
                    olddp[base+carry][d1][d2] = min({olddp[base+carry][d1][d2],olddp[base+carry][d1+1][d2],olddp[base+carry][d1][d2+1]});
                    if (olddp[base+carry][d1][d2]==INF)continue;
                    ll val = d1-d2+carry;
                    ll ncarry = val/10;
                    if (val<0 && num!=0)--ncarry;
                    if ((val%10+10)%10!=num)continue;
                    dp[base+ncarry][d1][d2] = min(dp[base+ncarry][d1][d2],ll(d1+d2+olddp[base+carry][d1][d2]));
                }
            }
        }
        swap(dp,olddp);
        for(ll carry = 0;carry<=base*2;++carry){
            for(ll d1 = 0;d1<=MAXN;++d1){
                for(ll d2 = 0;d2<=MAXN;++d2){
                    dp[carry][d1][d2] = INF;
                }
            }
        }
    }
    ll res = INF;
    for(ll d1 = MAXN;d1>=0;--d1){
        for(ll d2 = MAXN;d2>=0;--d2){
            res = min(res,olddp[base][d1][d2]);
        }
    }
    cout<<res<<endl;
    return 0;
}