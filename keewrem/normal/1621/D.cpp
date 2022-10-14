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
const int MAXN = 3000010;

void solve(){
	int N;
	cin >> N;
	int M = 2*N;
	vll v[M];
	for(int i = 0; i < M; i++){
		v[i].resize(M);
		for(int j = 0; j < M; j++)cin >> v[i][j];
	}
	ll c = min({v[N][N-1],v[N-1][N],v[0][N],v[N][0],
	v[N-1][M-1],v[M-1][N-1],v[M-1][0],v[0][M-1]});
	for(int i = 0; i < N; i++)for(int j = 0; j < N;j++)c += v[N+i][N+j];
	cout << c << endl;
	return;
}

int main(){
	int T = 1;
	cin >> T;
	while(T--)solve();
	return 0;
}