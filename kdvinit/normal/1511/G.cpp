#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5;
int a[N];

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n, m; cin>>n>>m;

    for(int i=0; i<n; i++) cin>>a[i];
    sort(a, a+n);

    string s;

    int q; cin>>q;
    while(q--)
    {
        int l, r; cin>>l>>r;
        int L = upper_bound(a, a+n, l) - a;
        int R = upper_bound(a, a+n, r) - a;
        int ans=0; for(int i=L; i<R; i++) ans^=(a[i]-l);
        s+="AB"[ans==0];
    }
    cout<<s;
}