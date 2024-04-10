//#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int LOG = 23;
const int N = (1<<LOG)+100;
const int SZ = (1<<LOG)-1;
int po[LOG+2];
int A[N];
pair<int,int> dp[N][2];
int last[N];
void asgn(pair<int,int> &a,int val){
    a.second = max(a.second,val);
    if (a.first<a.second)
        swap(a.first,a.second);
}
void merge(pair<int,int> &a,pair<int,int> b){
    asgn(a,b.first);
    asgn(a,b.second);
}
void calc(){
    int t = 0;
    for(int bit = 1;bit<=LOG;++bit){
        for(int mask = 0;mask<=SZ;++mask){
            dp[mask][t^1] = dp[mask][t];


            if (mask&po[bit-1]){
                merge(dp[mask][t^1],dp[mask-po[bit-1]][t]);
            }
            if (bit==LOG)
                last[SZ-mask] = dp[mask][t^1].second;
        }
        t^=1;
    }
}
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    po[0] = 1;
    for(int i = 1;i<LOG+2;++i)
        po[i] = po[i-1]*2;
    int n;
    cin>>n;
    for(int i = 1;i<=n;++i){
        cin>>A[i];
        asgn(dp[SZ-A[i]][0],i);
    } ///sadasdsadas
    calc();
    int res = 0;
    for(int i = 1;i<=n;++i){
        int sum = 0;
        for(int bit = LOG-1;bit>=0;--bit){
            if (A[i]&po[bit]){
                continue;
            }
            if (last[sum+po[bit]]>i){
                sum+=po[bit];
            }
        }
        if (last[sum]>i)
            res = max(res,sum+A[i]);
    }
    cout<<res<<endl;

    return 0;
}