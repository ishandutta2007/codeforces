#include<bits/stdc++.h>
#pragma gcc optimise("O3")
using namespace std;
#define fi first
#define se second
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back
#define pf push_front
#define ps push
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x) int((x).size())
template<typename T>
using pq = priority_queue<T>;
#define FOR(i,k) for(int i = 0; i < (k); i++)
#define foll(i,k) for(long long i = 0; i < (k); i++)
#define FORr(i,k) for(int i = (k)-1; i >= 0; i--)
#define folr(i,k) for(long long i = (k)-1; i >= 0; i--)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD =   1000000007;//   998244353;
multiset<pll> s;
ll c[200010], t[200010], x[200010];
unordered_map<ll,ll> m;
void ins(ll l, ll r){
    s.insert({r,l});
    auto x = s.find({r,l});
    multiset<pll>::iterator st = x,e = x;
    //cout << "Lol"<<endl;
    pll p = {-1,-1};
    while(x!=s.begin()){
        x--;
        if(l > (*x).se)break;
        else e = x;
    //    cout << " kk"<<endl;
    }
    s.erase(e,st);
    if(p.se != -1)s.insert(p);
    x = s.find({r,l});
    st = x; st++; e = x;
    while(1){
        x++;
        if(x == s.end() || (*x).fi > l)break;
        e = x;
    }
    e++;
    s.erase(st,e);
}

void solve(){
    int N,M; cin >> N >> M;
    vector<pii> v(N);
    for(int i = 0; i < N; i++){
        cin >> x[i] >> t[i];
        v[i] = {x[i]+t[i],-x[i]};
        m[x[i]] = i;
    }
    sort(all(v));
    for(auto x: v)ins(-x.se,x.fi);
    ll a,b; pll p;
    v.resize(M);
    for(auto &x: v)cin >> x.fi >> x.se;
//    sort(all(v));
    multiset<pll> ms;
    for(auto q: v){
        a = q.fi; b = q.se;
        /*cout <<"----multiset----\n";
        for(auto x: s)cout << x.se << " " << x.fi << endl;
        cout << "--MOSQ---\n";
        for(auto x: ms)cout << x.fi << " " << x.se << endl;
        */
        auto x = s.lower_bound({a,-1});
        if(x == s.end()){ms.insert(q);continue;}
        p = *x;
        if(p.se > a){ms.insert(q);continue;}
        auto k = ms.lower_bound({p.fi,-1});
        t[m[p.se]]+=b;
        c[m[p.se]]++;
        p.fi+=b;
        multiset<pll>::iterator st = k,e = k;
        //cout << "aa" << endl;
        while(1){
            if(k == ms.end() || (*k).fi > p.fi)break;
            t[m[p.se]]+=(*k).se;
            c[m[p.se]]++;
            p.fi+=(*k).se;
            k++;
            e = k;
        }
        ms.erase(st,e);
        s.erase(x);
        ins(p.se,p.fi);
    }
    for(int i = 0; i < N; i++)cout << c[i] << " " << t[i] << "\n";
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