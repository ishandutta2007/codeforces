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
vector<int> V[N];
void solve(){
    int n,k;
    cin>>n>>k;
    int mi = 1e5,mx = 0;
    for(int i = 1;i<=n;i+=1){
        cin>>A[i];
        if (n==1){
            cout<<"0\n";
            return;
        }
        V[A[i]].push_back(i);
        mx = max(mx,A[i]);
        mi = min(mi,A[i]);
        dv[i] = 1;
    }

    int res = mx-mi;
    for(int i = mx;i>=1;){

        while(V[i].empty()){
            V[i].clear();
            V[i].shrink_to_fit();
            i -= 1;
        }
        res = min(res,i-mi);
        if (res==0){
            break;
        }
        int base = i;
        int ind = V[i].back();
        if (dv[ind]==k){
            break;
        }
        V[i].pop_back();
        int need = min(k,A[ind]/mi);
        if (A[ind]/need==base){
            need = A[ind]/base+1;
            assert(A[ind]/need<base);
        }
        if (need>k){
            break;
        }
        dv[ind] = need;
        V[A[ind]/dv[ind]].push_back(ind);
        mi = min(mi,A[ind]/dv[ind]);

    }
    cout<<res<<endl;
    for(int i = 0;i<=mx;i+=1){
        V[i].clear();
        V[i].shrink_to_fit();
    }
    //cout<<V[4].capacity()<<endl;
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