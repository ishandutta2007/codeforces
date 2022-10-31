//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int DIM = 1E5+7;
const int LOG = 30;
void solve(){
    int n,m;
    cin>>n>>m;
    if (n>m){
        cout<<0<<endl;
        return;
    }
    int cur = 0;
    while(1) {
        int last = -1;
        for (int bit = 0; bit <= 30; ++bit) {
            if (cur & (1 << bit))
                break;
            int num = cur ^(1 << bit) ^n;
            if (num > m)
                break;
            last = bit;
            int val = 1<<(bit+1);
            int nu = (cur^n)|(val-1);
            if (nu>m)
                break;
        }
        if (last==-1)
            break;
        cur^=(1<<last);
    }
    cout<<cur+1<<endl;
}
int main()
{
//    freopen("events.in","r",stdin);
//    freopen("events.out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
/**
1
6 3
111001
111100
10 3
1101000000
1011000000

**/