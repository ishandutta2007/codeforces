#include <bits/stdc++.h>
#define ld long double
#define ll long long int
#define st first
#define nd second
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
 
using namespace std;
 
const int N = 4e5 + 5;
vector<int> pos;
int n, k;
 
bool can(int cnt){
    ll sum = 0;
    ll tmp = cnt;
    for(int i=pos.size()-1;i>=(int)pos.size()-cnt;i--){
        sum += pos[i];
    }
    ll need = (ll)n * tmp;
    need -= sum;
    return need < (ll)n;
}
 
void solve(){
    cin >> n >> k;
    pos.clear();
    for(int i=1;i<=k;i++){
        int x; cin >> x;
        pos.pb(x);
    }
    sort(pos.begin(), pos.end());
    int L = 0;
    int R = k;
    while(L + 1 < R){
        ll mid = (L + R) / 2;
        if(can(mid)) L = mid;
        else R = mid;
    }
    ll ans = L;
    if(can(R)) ans = R;
    cout << ans << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    int tt = 1;
    cin >> tt;
    while(tt--) solve();
 
    return 0;
}