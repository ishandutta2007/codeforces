//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int N = 107;
int last[N];
pair<int,int> ans[N];
void solve(){
    int n,k;
    cin>>n>>k;
    int div = n/(k-1)+(n%(k-1)!=0);
    div = n/div+(n%div!=0);
    for(int i = 1;i<=n*k;++i){
        int x;
        cin>>x;
        if (last[x] && !ans[x].first){
            int l = x/div+(x%div!=0);
            ans[x] = {last[x],i};
            for(int j = (l-1)*div+1;j<=min(n,l*div);++j){
                last[j] = 0;
            }
        }
        else
            last[x] = i;
    }
    for(int i = 1;i<=n;++i){
        cout<<ans[i].first<<' '<<ans[i].second<<endl;
    }

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