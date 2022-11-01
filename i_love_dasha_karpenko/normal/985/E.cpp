//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int N = 5E5+7;
int A[N];
void solve(){

    int n,k,d;
    cin>>n>>k>>d;
    for(int i = 1;i<=n;++i)
        cin>>A[i];
    sort(A+1,A+1+n);
    vector<int> valid = {0};
    int ptr = 1;
    for(int i = 1;i<=n;++i){
        while(A[i]-A[ptr]>d)
            ++ptr;
        auto pos = lower_bound(valid.begin(),valid.end(),ptr-1);
        if (pos!=valid.end() && i-*pos>=k)
            valid.push_back(i);
    }
    if (!valid.empty() && valid.back()==n)
        cout<<"YES\n";
    else cout<<"NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t;
    t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}