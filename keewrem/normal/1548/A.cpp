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


void solve(){
	int N,M;
	cin >> N >> M;
	vi hc(N,0);
	int a,b,d;
	int c = N;
	while(M--){
		cin >> a >> b;
		if(a > b)swap(a,b);
		if(hc[a]++ == 0)c--;
	}
	int q;
	cin >> q;
	while(q--){
		cin >> d;
		if(d == 3)cout << c << endl;
		else if(d == 1){
			cin >> a >> b;
			if(a > b)swap(a,b);
			if(hc[a]++ == 0)c--;
		}else{
			cin >> a >> b;
			if(a > b)swap(a,b);
			if(--hc[a] == 0)c++;
		}
	}
	return;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(NULL);
    int T = 1;

//    cin >> T;

    while(T--){
        solve();
    }
}