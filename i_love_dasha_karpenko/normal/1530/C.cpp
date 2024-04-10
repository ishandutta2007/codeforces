//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int N = 1E5+7;
int A[2][N];
void solve(){
    int n;
    cin>>n;
    for(int c = 0;c<2;++c)
    for(int i = 1;i<=n;++i){
        cin>>A[c^1][i];
    }
    for(int c = 0;c<2;++c)
        sort(A[c]+1,A[c]+1+n,greater<int>());
    int l = 0,r = n;
    while(l<r){
        int tm = (l+r)/2;
        int stp = tm+n-(tm+n)/4;
        ll rr = 0;
        for(int i = 1;i<=min(n,stp);++i)
            rr+=A[0][i];

        int g = min(tm,stp);
        ll cur = 100ll*g;
        for(int i = 1;i<=stp-g;++i)
            cur+=A[1][i];
        if (cur>=rr)
            r = tm;
        else l = tm+1;
    }
    cout<<l<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int t;
    //t = 1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}