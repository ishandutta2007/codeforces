#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#include <bits/stdc++.h>
using namespace std;
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    int mxn = (int)2e7;
    int freq[mxn+5];
    memset(freq,0,sizeof(freq));
    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        freq[x]++;
    }
    for(int i = 1; i<=mxn; i++){
        for(int j = i*2; j<=mxn; j+=i){
            freq[i]+=freq[j];
        }
    }
    long long dp[mxn+5];
    memset(dp,0,sizeof(dp));
    dp[1] = n;
    long long ans = n;
    for(int i = 1; i<=mxn; i++){
        if(!freq[i])continue;
        for(int j = 2*i; j<=mxn; j+=i){
            if(!freq[j])continue;
            dp[j] = max(dp[j],dp[i]+(long long)freq[j]*(j-i));
        }
        ans = max(ans,dp[i]);
    }
    cout << ans << "\n";
    return 0;
}