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
    int N, o = 0, e = 0;
    int a;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a;
        if(a%2)o++;
        else e++;
    }
    int w[2][4] = {{0,1,1,0},{0,0,1,0}};
    if(w[e%2][o%4])cout << "Bob" << endl;
    else cout << "Alice" << endl;


	return;
}

int main(){
	int T = 1;
	cin >> T;
	while(T--)solve();
	return 0;
}