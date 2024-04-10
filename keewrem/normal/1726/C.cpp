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
    string s;
    int N;
    cin >> N;
    cin >> s;
    int ans = N;
    for(int i = 1; i < 2*N; i++)if(s[i] == '(' && s[i-1] == ')')ans--;
    cout << ans << endl;
	return;
}

int main(){
	int T = 1;
	cin >> T;
	while(T--)solve();
	return 0;
}