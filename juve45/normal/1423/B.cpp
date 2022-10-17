#include <bits/stdc++.h>
using namespace std;
void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.first << ' ' << p.second << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}
#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(ll _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int,int>
#define MOD 1000000007
#define zeros(x) x&(x-1)^x
#define fi first
#define se second
#define Nmax 20005
const long double PI = acos(-1);

int n,m,c,st[2*Nmax],dr[2*Nmax],a,b;
bool uz[Nmax];
vector<int> v[2*Nmax];
 
bool cup(int nod){
    uz[nod] = 1;
    for (auto it : v[nod]){
        if (!dr[it]){
            dr[it] = nod;
            st[nod] = it;
            return 1;
        }
    }
    for (auto it : v[nod]){
        if (!uz[dr[it]] && cup(dr[it])){
            dr[it] = nod;
            st[nod] = it;
            return 1;
        }
    }
 
    return 0;
}

struct edge{
	int a,b,c;
};

vector<edge> E2;

int _try(int x){
	for (int i=0;i<=2*n+1;i++){
		v[i].clear();
	}
	memset(st,0,sizeof(st));
	memset(dr,0,sizeof(dr));

	for (auto it : E2){
  	if (it.c > x) continue;
  	// dbg(it.a, it.b);
  	v[it.a].push_back(it.b);
    v[it.b].push_back(it.a);
	}

	int ok = 1;
  while(ok){
    ok = 0;
    memset(uz,0,sizeof(uz));
    for (int i=1;i<=n;i++)
      if (!st[i] && !uz[i]) ok |= cup(i);
  }

  int nr = 0;
  for (int i=1;i<=n;i++) if (st[i]) nr++;

	
	return nr == n;
}

int main(){
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (ll i=1;i<=m;i++){
  	int p,q,c;
  	cin >> p >> q >> c;
  	q += n;
  	E2.push_back({p,q,c});
  }


  int p = 1, st = 0;
  for (;p<=1e9;p<<=1);
  for (;p>=1;p>>=1){
  	if (st + p < 1e9 && !_try(st+p)){
  		st += p;
  	}
  }
  st++;

  if (!_try(st)){
  	cout << "-1\n";
  }
  else cout << st << '\n';

  return 0;
}