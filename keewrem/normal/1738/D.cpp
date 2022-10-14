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
    vector<vector<int>> pos(N+2);
    
    for(int i = 0; i < N; i++){
        cin >> v[i]; pos[v[i]].push_back(i);
    }
    vector<int> perm (N);
    int id = 0;    
    int t = 0;
    int p = 0;
    vector<int> last;

    if(pos[0].empty()){
        for(auto x: pos[N+1])if(pos[x+1].empty())perm[id++] = x+1;
        for(auto x: pos[N+1])if(pos[x+1].size())perm[id++] = x+1;
        last = pos[N+1];
        t += pos[N+1].size();
        ++p;
    }else{
        last = pos[0];
        for(auto x: pos[0])if(pos[x+1].empty())perm[id++] = x+1;
        for(auto x: pos[0])if(pos[x+1].size())perm[id++] = x+1;
    }
    int i; 
    while(id < N){
        for(auto x: last)if(pos[x+1].size())i = x+1;
        if((++p)%2)t += pos[i].size();
        for(auto x: pos[i])if(pos[x+1].empty())perm[id++] = x+1;
        for(auto x: pos[i])if(pos[x+1].size())perm[id++] = x+1;
        last = pos[i];
    }
    cout << t << endl;
    for(auto x: perm)cout << x << ' ';
    cout << endl;

	return;
}

int main(){
	int T = 1;
	cin >> T;
	while(T--)solve();
	return 0;
}