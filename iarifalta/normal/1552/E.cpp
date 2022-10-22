#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define si short int
#define speed ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pill pair<ll,ll>
#define f first
#define s second
#define pilc pair<ll,char>
#define all(a) (a).begin(),(a).end()
#define rep(s,e,step) for(int i = (s); i < (e) ; i += step)
#define vrep(s,e,step) for(int j = (s); j < (e) ; j += step)
#define ex exit(0) 
#define sz(a) (a).size()
#define triple pair<pill, ll>
#define pinode pair<node*, node*>
#define quadra pair<pill, pill>
#define ld long double
using namespace std;
 
const ll N = 3e5 + 10;
const ll M = 1e4 + 10;
const ll big = 1e17;
const ll hsh2 = 1964325029 ;
const long long mod = 1e9 + 7;
const long double EPS = 1e-10;
const ll block = 1e7;
const ll shift = 2e3;
const ld pi = acos(-1.0);

ll n, k;
vector<pill> p;
ll a[N];
ll lst[N];
pill ans[N];

bool was[N];


int main() {
	speed;
	cin >> n >> k;
	vector<pill> p;
	for(int i = 1; i <= n * k; i++) {
		cin >> a[i];
		if(lst[a[i]])
			p.pb(mp(i, lst[a[i]]));			
		lst[a[i]] = i;
	}
	sort(all(p));
	multiset<int> tel;
	ll pa = (n + (k - 2)) / (k - 1);
	for(int i = 1; i <= pa; i++)
		tel.insert(0);		
	int cnt = 0;
	vector<pill> f;
	for(auto u : p) {
		if(*tel.begin() < u.s && !was[a[u.s]]) {
		   	ans[a[u.s]] = u;
			was[a[u.s]] = 1;
			tel.erase(tel.begin());
			tel.insert(u.f);
			f.pb(u);
		}
	}
	for(int i = 1; i <= n; i++)
		cout << ans[i].s << " " << ans[i].f << '\n';
}
/*
*/