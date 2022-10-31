//#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define gt(tuple,el) (get<el>(tuple))
const int N = 2e5+7;
const int AL = 17;
const int masksz = 1<<AL;
int A[N],D[AL][N],min_len[masksz],po[AL];
int n,k;
int solve(int need){
    for(int symb = 0;symb<k;++symb){
        int *dp = D[symb];
        int len = 0;
        for(int i = 1;i<=n;++i){
            dp[i] = 0;
            if (A[i]==-1 || A[i]==symb)
                ++len;
            else len = 0;
            if (len>=need)
                dp[i-need+1] = i;
        }
        dp[n+1] = -1;
        for(int i = n;i>=1;--i){
            if (dp[i]==0)
                dp[i] = -1;
            if (dp[i+1]!=-1){
                if (dp[i]==-1)
                    dp[i] = dp[i+1];
                else dp[i] = min(dp[i],dp[i+1]);
            }
            //D[symb][i] = dp[i];
        }

    }
    min_len[0] = 0;
    int sz = 1<<k;
    for(int mask = 1;mask<sz;++mask){
        min_len[mask] = -1;
        for(int bit = 0;bit<k;++bit){
            if (!(mask&po[bit]))
                continue;
            int submask = mask^po[bit];
            if (min_len[submask]==-1)
                continue;
            int start_pos = min_len[submask]+1;
            if (D[bit][start_pos]==-1)
                continue;
            int val = D[bit][start_pos];
            if (min_len[mask]==-1)
                min_len[mask] = val;
            min_len[mask] = min(min_len[mask],val);
        }
    }
    if (min_len[sz-1]!=-1)
        return 1;
    return 0;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    po[0] = 1;
    for(int i = 1;i<AL;++i)
        po[i] = po[i-1]*2;
    cin>>n>>k;
    for(int i = 1;i<=n;++i){
        char ch;
        cin>>ch;
        if (ch!='?')
            A[i] = ch-'a';
        else A[i] = -1;
    }
    int l = 0,r = n;
    while(l!=r){
        int tm = (l+r+1)>>1;
        if (solve(tm))
            l = tm;
        else r = tm-1;
    }
    cout<<l<<endl;
    return 0;
}