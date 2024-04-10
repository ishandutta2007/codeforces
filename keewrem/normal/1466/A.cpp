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

int T = 1;
ll N;

void solve(){
    cin >> N;
    vi v(N);
    for(auto &x: v)cin >> x;
    set<int> s;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < i; j++)s.insert(abs(v[i]-v[j]));
    }
    cout << s.size()<<"\n";

}

int main(){
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}