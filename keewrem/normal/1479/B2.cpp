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


void solve(){
    int N; cin >> N;
    vi v(N); for(int &i: v)cin >> i;
    vi s[N+1];
    FOR(i,N)s[v[i]].pb(i);
    vi ind(N+1);
    int a = 0,b = 0, ans = 0;
    for(int i = 0; i < N; i++){

        while(ind[a] < s[a].size() && s[a][ind[a]] < i)ind[a]++;
        while(ind[b] < s[b].size() && s[b][ind[b]] < i)ind[b]++;
        if(a == v[i] || b == v[i])continue;
        if(ind[b] >= s[b].size()){
            if(b != v[i])ans++;b = v[i];
        }else if(ind[a] >= s[a].size() || s[b][ind[b]] < s[a][ind[a]]){
            if(a != v[i])ans++;a = v[i];
        }else{
            if(b != v[i])ans++;b = v[i];
        }
        //cout << a << " "<< b << endl;
    }
    cout << ans << endl;
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