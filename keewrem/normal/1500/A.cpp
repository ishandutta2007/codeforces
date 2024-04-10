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
vi v;
bool comp(const pii &a, const pii &b){
    return v[a.fi]+v[a.se] < v[b.fi]+v[b.se];
}
int s(pii a){
    return v[a.fi] + v[a.se];
}
bool diff(pii a, pii b){
    return ((a.fi != b.fi && a.fi != b.se) &&
        (a.se != b.fi) && (a.se != b.se));
}
vector<pii> c[5000010];
void solve(){
    int N; cin >> N;
    v.resize(N); for(int &i: v)cin >> i;

        for(int i = 0; i < N; i++){
            for(int j = 0; j < i; j++){
                for(auto x: c[v[i]+v[j]]){
                    if(diff({i,j},x)){
                        cout << "YES\n" << i+1 << " " << j+1<<" ";
                        cout << x.fi+1 << " " << x.se+1 << endl;
                        return;
                    }
                }
                c[v[i]+v[j]].pb({i,j});
            }
        }
    cout << "NO\n";
    return;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(NULL);
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}