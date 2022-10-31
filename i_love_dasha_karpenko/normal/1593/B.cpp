
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 19;
int A[N];
void solve(){
    ll n;
    cin>>n;
    for(int i = 0;i<N;++i){
        A[i] = n%10;
        n/=10;
    }
    int res = N;
    for(int last = 0;last<100;last+=25){
        int ps = 0,lt = -1;
        for(int i = 0;i<N;++i){
            if (ps==0 && A[i]==last%10)
                ++ps;
            else if(ps==1 && A[i]==last/10){
                lt = i;
                break;
            }
        }
        if (lt==-1)
            continue;
        int flag = 0;
        for(int i = lt+1;i<N;++i){
            if (A[i]){
                flag = 1;
                break;
            }
        }
        if (last==0 && !flag)
            continue;
        res = min(res,lt-1);
    }
    cout<<res<<endl;
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();


    return 0;
}