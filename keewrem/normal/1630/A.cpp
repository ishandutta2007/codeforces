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

	int N,K;
	cin >> N >> K;
	vi v(N,0), pos(N);
	for(int i = 0; i < N/2; i++){pos[i] = 2*i; pos[i^(N-1)] = 2*i+1;}
	for(int i = 1; i < N; i*=2){
		if((K&i) == 0)continue;
		swap(pos[i],pos[0]);
	}
	for(int i = 0; i < N; i++)v[pos[i]] = i;
	int s = 0; for(int i = 0; i < N; i+=2){
		s += v[i]&v[i+1];
	}
	if(s!=K)cout << "-1\n";
	else for(int i = 0; i < N; i++)cout << v[i] << " \n"[i%2];
	return;
}

int main(){
	int T = 1;
	cin >> T;
	while(T--)solve();
	return 0;
}