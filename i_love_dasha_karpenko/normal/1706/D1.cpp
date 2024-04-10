//#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
//#define int ll
const int N = 1e5+7;
int A[N],dv[N];
void solve(){
    int n,k;
    cin>>n>>k;
    set<pair<int,int> > S;
    for(int i = 1;i<=n;i+=1){
        cin>>A[i];
        S.insert({A[i],i});
        dv[i] = 1;
    }
    if (n==1){
        cout<<"0\n";
        return;
    }
    int res = S.rbegin()->first-S.begin()->first;
    while(1){

        int ind = S.rbegin()->second;
        if (dv[ind]==k){
            break;
        }
        S.erase(prev(S.end()));
        int mi = S.begin()->first;
        int need = min(k,A[ind]/mi);
        if (dv[ind]<need){
            dv[ind] = need;
        }
        else{
            dv[ind] = need+1;
        }
        S.insert({A[ind]/dv[ind],ind});
        res = min(res,S.rbegin()->first-S.begin()->first);
        if (res==0){
            break;
        }
    }
    cout<<res<<endl;

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}