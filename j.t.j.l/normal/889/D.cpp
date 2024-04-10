#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e3 + 10;
const int MAXM = 2e6 + 10;

int n;

struct Pt{
	long long x, y;
};

bool operator < (const Pt & a, const Pt & b){
	if (a.x == b.x)
		return a.y < b.y;
	else
		return a.x < b.x;
}

bool operator == (const Pt & a, const Pt & b){
	return a.x == b.x && a.y == b.y;
}

inline long long operator * (const Pt & a, const Pt & b){
	return a.x * b.y - a.y * b.x;
}

inline long long operator % (const Pt & a, const Pt & b){
	return a.x * b.x + a.y * b.y;
}

inline Pt operator - (const Pt & a, const Pt & b){
	return (Pt){a.x - b.x, a.y - b.y};
}

inline Pt operator + (const Pt & a, const Pt & b){
	return (Pt){a.x + b.x, a.y + b.y};
}

inline Pt operator * (const Pt & a, const ll u){
	return (Pt){a.x * u, a.y * u};
}

long long sqr(long long x){
	return x * x;
}

inline double len(const Pt & a){
	return sqrt(sqr(a.x) + sqr(a.y));
}

long long absll(long long x){
	return x < 0 ? -x : x;
}

vector<Pt> convex_hull(vector<Pt> u){
    sort(u.begin(), u.end()); 
    u.erase(unique(u.begin(), u.end()), u.end()); 
    if (u.size() < 3) 
		return u;
    vector<Pt> c;
    for(int i=0, o=1, m=1; ~i; i += o){
        while(c.size() > m){
            Pt a = c.back() - c[c.size() - 2];
            Pt b = c.back() - u[i];
            if (a * b < 0) 
				break; // <= 0  
            c.pop_back();
        }
        c.push_back(u[i]);
        if(i + 1 == u.size()) 
			m = c.size(), o = -1;
    }
    c.pop_back();
    return c;
}

set<PII> PP, LL, PL;

void addpp(int u, int v){
	u %= n, v %= n;
	if (u > v) swap(u, v);
	PP.insert(PII(u, v));
}

void addpl(int u, int v){
}

void addll(int u, int v){
}

void xzkk(vector<Pt>& c){
	auto Area = [&](int u, int v, int w){
		u %= n, v %= n, w %= n;
		return abs((c[u] - c[v]) * (c[w] - c[v]));
	};
	int tmpn = n;
	n = c.size();
	int v = 0, u = 1;
	while(Area(v,v+1,u+1)>
			Area(v,v+1,u)) 
		u++;
	PP.clear();
	PL.clear();
	LL.clear();
	addpp(v, u);
	addpp(v+1, u);
	addpl(u, v);
	for(int i=0;i<=4*n;i++){
	  addpp(u, v);
	  if (i & 1){
	    if ((c[(v+1)%n]-c[v%n])*
	        (c[(u+1)%n]-c[u%n]) > 0)
		  swap(u, v);
	  }
	  else{
		addpp(u, v+1);
		addpl(u, v);
		if (Area(v, v+1, u) 
			==Area(v,v+1,u+1)){
		  addpp(u+1, v);
		  addpp(u+1, v+1);
		  addpl(u+1, v);
		  addpl(v, u);
		  addpl(v+1, u);
		  addll(u, v); 
		  u++;
		}
		v++;
	  }
	}
	n = tmpn;
}

ll ans;
vector<Pt> a;

vector<Pt> ret;

void check(Pt dir, Pt&U, Pt&V){
	ll r = __gcd(abs(dir.x), abs(dir.y));
	dir.x /= r, dir.y /= r;
	if (dir.x < 0){
		dir.x = -dir.x;
		dir.y = -dir.y;
	}
	if (dir.x == 0 && dir.y < 0){
		dir.y = -dir.y;
	}
	//vector<__int128> F;
	//__int128 A = dir.x;
	//__int128 B = dir.y;
	vector<ll> F;
	ll A = dir.x, B = dir.y;
	ll UVx = U.x + V.x;
	ll UVy = U.y + V.y;
	ll sm = A * UVx + B * UVy;
	for (auto &p : a){
		F.push_back(A * p.x + B * p.y);
	}
	sort(F.begin(), F.end());
	for (int i = 0; i * 2 < F.size(); i++){
		if (F[i] + F[F.size() - 1 - i] != sm){
			return ;
		}
	}
	ret.push_back(dir);
}

ll nico = 453209;
ll maki = 453757;

void gao(Pt U, Pt V){
	ll sx = 0;
	ll sy = 0;
	ll sxx = 0;
	ll syy = 0;
	ll sxy = 0;
	ll UVx = U.x + V.x + 2 * nico;
	ll UVy = U.y + V.y;
	for (auto &p : a){
		sx += p.x;
		sy += p.y;
		sxx += sqr(p.x + nico) - sqr(UVx - p.x + nico);
		syy += sqr(p.y) - sqr(UVy - p.y);
		sxy += (p.x + nico) * p.y - (UVx - p.x + nico) * (UVy - p.y);
	}
	sx = sx * 2 - n * (U.x + V.x);
	sy = sy * 2 - n * (U.y + V.y);
	/*
	cerr << "+++++++++++++++++++++++++++++" << endl;
	cerr << U.x << ' ' << U.y << ' ' << V.x << ' ' << V.y << endl;
	cerr << sx << ' ' << sy << ' ' << sxx << ' ' << syy << ' ' << sxy << endl;
	*/
	if (sx == 0){
		if (sy != 0)
			check((Pt){1ll, 0ll}, U, V);
		else{
			sxy *= 2;
			if (sxx == 0 && syy == 0){
				ans = 1ll << 60;
			}
			ans = 1ll << 60;
			/*
			else{
				if (sxx != 0){
					__int128 del = (__int128)sxy * sxy - (__int128)4 * sxx * syy;
					ll tmp = sqrt((long double)del);
					while (tmp * tmp < del) tmp++;
					while (tmp * tmp > del) tmp--;
					if (tmp * tmp != del)
						return ;
					check((Pt){-sxy+tmp, 2*sxx}, U, V);
					check((Pt){-sxy-tmp, 2*sxx}, U, V);
				}
				else{
					__int128 del = (__int128)sxy * sxy - (__int128)4 * sxx * syy;
					ll tmp = sqrt((long double)del);
					while (tmp * tmp < del) tmp++;
					while (tmp * tmp > del) tmp--;
					if (tmp * tmp != del)
						return ;
					check((Pt){2*syy, -sxy+tmp}, U, V);
					check((Pt){2*syy, -sxy-tmp}, U, V);
				}
			}
			*/
		}
	}
	else{
		if (sy != 0){
			check((Pt){sy, -sx}, U, V);
		}
		else{
			check((Pt){0ll, 1ll}, U, V);
		}
	}
}

void restore(){
	if (ans >= 1ll << 60)
		return ;
	sort(ret.begin(), ret.end(), [](const Pt & a, const Pt & b){
		if (a.x == b.x) return a.y < b.y;
		else return a.x < b.x;
	});
	ret.erase(unique(ret.begin(), ret.end()), ret.end());
	ans = ret.size();
}

int vis[2222];

void solve(){
	scanf("%d", &n);
	a.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%lld%lld", &a[i].x, &a[i].y);
	Pt O;
	O.x = O.y = 0;
	for (int i = 0; i < n; i++)
		O = O + a[i];
	if (O.x * 2 % n == 0 && O.y * 2 % n == 0){
		O.x = O.x * 2 / n;
		O.y = O.y * 2 / n;
		for (int i = 0; i < n; i++)
			if (a[i] * 2 == O){
				vis[i] = 1;
			}
			else if (!vis[i]){
				for (int j = i + 1; j < n; j++)
					if (!vis[j] && a[i] + a[j] == O){
						vis[i] = 1, vis[j] = 1;
						break;
					}
			}
		vector<Pt> c;
		for (int i = 0; i < n; i++)
			if (!vis[i]){
				c.push_back(a[i]);
			}
		a.swap(c);
		c.clear();
		n = a.size();
	}
	if (n == 0){
		puts("-1");
		return ;
	}
	vector<Pt> b = convex_hull(a);
	xzkk(b);
	ans = 0;
	for (auto &x : PP){
		if (x.first != x.second)
			gao(b[x.first], b[x.second]);
	}
	restore();
	if (ans >= 1ll << 60){
		puts("-1");
	}
	else
		printf("%lld\n", ans);
}

int main(){
	solve();
	return 0;
}