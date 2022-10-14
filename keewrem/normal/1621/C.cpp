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

int query(int i){
	cout << "? " << i << endl;
	cout.flush();
	cin >> i;
	return i;
}

void solve(){
	int N; cin >> N;
	vi v(N+1,0);
	vi ans(N+1);
	for(int i = 1; i <= N; i++){
		if(v[i])continue;
		vi k;
		int in = query(i);
		k.pb(in);
		int cur;
		do{
			cur = query(i);
			k.pb(cur);
		}while(cur != in);
		for(int i = 0; i < k.size()-1; i++){
			v[k[i]] = 1;
			ans[k[i]] = k[i+1];
		}
	}
	cout.flush();
	cout << "!";
	for(int i = 0; i < N; i++)cout <<" "<< ans[i+1];
	cout << endl;
	cout.flush();
	return;
}

int main(){
	int T = 1;
	cin >> T;
	while(T--)solve();
	return 0;
}