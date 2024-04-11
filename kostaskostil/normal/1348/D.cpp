#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int nmax=5e5+100;
#define int long long

vector<int> ans(int n)
{
//    if (n==2)
//    return {0};
//    if (n==3)
//    return {1};
//    if (n==4)
//    return {0, 1};
     vector<int> res;
        int s=1;
        int cnt=1;
    while (true)
    {
        if (n<s+cnt*4)
        {
            /// n>=s+cnt
            if (n<=s+2*cnt)
                {res.pb(n-s-cnt); return res;}
            if (n<=s+3*cnt)
                {res.pb(0); res.pb(n-s-2*cnt); return res;}
            res.pb(3*cnt/2 - cnt), res.pb(n-s-3*cnt/2-3*cnt/2);
            return res;
        }
        else
        {
            res.pb(cnt);
            cnt*=2;
            s+=cnt;
        }
    }
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ttt;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++)
    {
        int n;
        cin>>n;
        auto res=ans(n);
        cout<<res.size()<<"\n";
        for (int i:res)
            cout<<i<<" ";
        cout<<"\n";
    }
}