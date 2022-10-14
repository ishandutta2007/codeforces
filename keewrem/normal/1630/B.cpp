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
	int N,K;  cin >> N >> K;
	vi v(N);
	for(auto &x: v)cin >> x;
	vi sus(N+1,0);
	for(auto x: v)sus[x]++;
	for(int i = 0; i < N; i++)sus[i+1] += sus[i];
	int mn = N+69420, bestl = 0, bestr = 0;
	int r = 0;
	for(int i = 0; i < N; i++){
		while(r < N && sus[r]-sus[i] < N-sus[r]+sus[i]+K)r++;
		if(r == N && sus[r]-sus[i] < N-sus[r]+sus[i]+K)break;
		if(r-i < mn){
			mn = r-i;
			bestr = r;
			bestl = i+1;
		}
	}
	cout << bestl << " " << bestr << "\n";
	for(int i = 0; i < N;){
		int c = 0;
		r = i;
		K--;
		while(c <= 0 || ((K == 0) && r < N)){
			if(v[r] < bestl || v[r] > bestr)c--;
			else c++;
			r++;
		}
		cout << i+1 << " " << r << endl;
		i = r;
	}
	return;
}

int main(){
	int T = 1;
	cin >> T;
	while(T--)solve();
	return 0;
}