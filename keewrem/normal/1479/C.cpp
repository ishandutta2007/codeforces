#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back
#define pf push_front
#define ps push
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define sz(x) int(x.size())
template<typename T>
using pq = priority_queue<T>;
#define FOR(i,k) for(int i = 0; i < k; i++)
#define foll(i,k) for(long long i = 0; i < k; i++)
#define FORr(i,k) for(int i = k-1; i >= 0; i--)
#define folr(i,k) for(long long i = k-1; i >= 0; i--)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int kek[31];

void solve(){
    kek[0] = 1;
    for(int i = 0; i < 30; i++)kek[i+1] = 1 << i;
    int l, r; cin >> l >> r;
    r = r-l+1;
    cout << "YES\n";
    cout << 32 << " ";
    vector<pair<pii,int>> v;
    int k;
    for(int i = 0; i < 30; i++){
        k = 1 << i;
        if(k <= r){
            for(int j = 0; j <= i; j++){
                v.pb({{32-i-1,32-j},kek[j]});
            }
        }else if(k <= 2*r){
            int sus = 0;
            if(l > 1){
                for(int j = 0; j < 30; j++){

                    if(r  & (1 << j)){
                        v.pb({{1,32-j-1},l-1+sus});
                    }
                    sus += (r & (1 << j));
                }
            }else{
                r--; l++;
                v.pb({{1,32},1});
                for(int j = 0; j < 30; j++){

                    if(r  & (1 << j)){
                        v.pb({{1,32-j-1},l-1+sus});
                    }
                    sus += (r & (1 << j));
                }
            }
        }
    }
    cout << v.size() << endl;
    for(auto x: v){
        cout << x.fi.fi << " " << x.fi.se <<" "<< x.se << "\n";
    }
    return;
}

int main(){
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}