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
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x) (int)b((x).size())
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
const int MAXN = 3000010;

void solve(){
    int N; cin >> N;
    vector<int> v(N);
    for(auto &x: v)cin >> x;
    vector<vector<int>> diff(N+1);
    for(int i = 1; i < N; ++i){
        if(v[i-1] - v[i] < 0)continue;
        else diff[v[i-1]-v[i]].push_back(i);
    }
    vector<int> st;
    for(int i = 1; i <= N; i++){
        for(auto x: diff[i])st.push_back(x);
        if(st.empty())cout << 1 << ' ';
        else {
            cout << st.back() + 1 << ' ';
            st.pop_back();
        }
    }

    cout << endl;
	return;
}

int main(){
	int T = 1;
	cin >> T;
	while(T--)solve();
	return 0;
}