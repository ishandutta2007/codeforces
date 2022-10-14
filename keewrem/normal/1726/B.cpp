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
    int N,M; cin >> N >> M;
    if(M < N || (M%2 && N%2 == 0)){
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    if(N % 2){
        cout << (M-N+1) << ' ';
        for(int i = 0; i < N-1; i++)cout << 1 << ' ';
    }else{
        cout << (M-N+2)/2 << ' ';
        cout << (M-N+2)/2 << ' ';
        for(int i = 0; i < N-2; i++)cout << 1 << ' ';
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