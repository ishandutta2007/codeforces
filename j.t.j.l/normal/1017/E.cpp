#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e5 + 10;

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

inline ll sqr(const Pt & a){
	return sqr(a.x) + sqr(a.y);
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

ll pw(ll p, ll q){
    ll ret = 1;
    for (; q; q >>= 1){
        if (q & 1)
            ret = ret * p % MM;
        p = p * p % MM;
    }
    return ret;
}

void gao(vector<Pt>&a, int n){
    a.resize(n);
    for (int i = 0; i < n; i++)
        scanf("%lld%lld", &a[i].x, &a[i].y);
    a = convex_hull(a);
}

int lcs(const vector<ll> &s, int n) {
    for (int i = 0, j = 1, k, ci, cj; ;) {
        for (k = 0; k < n; ++k) {
            ci = s[(i + k) % n];
            cj = s[(j + k) % n];
            if (ci != cj) break;
        }
        if (k == n) return std::min(i,j);
        if (ci > cj) i += k + 1,i += i == j;
        else j += k + 1, j += i==j;
    }
    return -1;
}

void fuck(vector<Pt>&a, vector<ll>&f){
    int n = a.size();
    a.push_back(a[0]);
    a.push_back(a[1]);
    for (int i = 0; i < n; i++){
        f.push_back(sqr(a[i + 1] - a[i]));
        f.push_back((a[i] - a[i + 1]) * (a[i + 2] - a[i + 1]));
        f.push_back((a[i] - a[i + 1]) % (a[i + 2] - a[i + 1]));
    }
    int nn = n * 3;
    //for (auto &x : f)
    //    cerr << x << ' '; cerr << endl;
    int pos = lcs(f, nn);
    vector<ll> g;
    for (int i = pos; i < nn; i++)
        g.push_back(f[i]);
    for (int i = 0; i < pos; i++)
        g.push_back(f[i]);
    g.swap(f);
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    vector<Pt> a, b;
    gao(a, n);
    gao(b, m);
    if (a.size() != b.size()){
        puts("NO");
        return 0;
    }
    vector<ll> u, v;
    fuck(a, u);
    fuck(b, v);
    puts(u == v ? "YES" : "NO");
    return 0;
}