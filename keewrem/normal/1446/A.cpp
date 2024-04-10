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
ll N,W;

int main(){
    cin >> T;
    while(T--){
        cin >> N >> W; vector<pll> v(N);
        for(int i = 0; i < N; i++){v[i].se = i+1;cin >> v[i].fi;}
        vi ans;
        sort(v.rbegin(),v.rend());
        ll c=0; bool k = 1;
        for(auto x: v){
            if(c+x.fi<=W){c+=x.fi;ans.pb(x.se);}
            if(c >= (W+1)/2)k = 0;

        }
        if(k){cout << "-1\n"; continue;}
        cout << ans.size()<<"\n";
        for(auto x: ans)cout << x <<" ";
        cout <<"\n";
    }
    return 0;
}