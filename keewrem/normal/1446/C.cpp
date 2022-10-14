#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int T;
int N;
int solve(vi vv, int xo){

    if(xo > 0)for(auto &x: vv)x^=(1<<(xo-1));
    vector<vi> kek(31);
    int l = 30;
    for(auto x: vv){
        while(x < (1<<(l-1)))l--;
        kek[l].pb(x);
    }
    int sus = 0, p = 0;
    int ans = sus,k;
    for(int i = 30 ; i >= 0; i--){
        if(kek[i].size()==0)continue;
        p+=kek[i].size();
        if(kek[i].size()>1)ans = max(solve(kek[i],i)+sus+(p < vv.size()),ans);
        sus++;
    }
    ans=max(ans,sus);
/*    cout << "v ";
    for(auto x: vv)cout << x << " ";
    cout << "\n";
    cout << ans <<"\n";
*/    return ans;
}
int main(){
    cin >> N;
    vi v(N);
    for(auto &x: v)cin >> x;
    sort(v.rbegin(),v.rend());
    cout << N-solve(v,0)<<"\n";
    return 0;
}