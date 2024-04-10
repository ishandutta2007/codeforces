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
int N;
int query(int i){
    if (i == 0 || i == N+1)return 1000000000;
    cout << "? " << i << endl;
    cout.flush();
    int r; cin >> r; return r;
}

void solve(){
    cin >> N;
    int a,b,mid, ub = N+1, lb = 0;
    while(ub - lb > 10){
        mid = (ub+lb)/2;
        a = query(mid); b = query(mid+1);
        if(a > b)lb = mid;
        else ub = mid;
    }
    int k = lb;
    vi v(N);
    for(int i = lb; i <= ub; i++){
        v[i] = query(i);
        if(v[i] < v[k]) k = i;
    }
    cout << "! " << k << endl;
    cout.flush();
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