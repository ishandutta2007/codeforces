#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e3 + 10;
const int MAXM = 2e6 + 10;

struct Pt{
	double x, y;
};

inline int equal(double p, double q){
	return fabs(p - q) < eps;
}

bool operator < (const Pt & a, const Pt & b){
	if (equal(a.x,b.x))
		return a.y < b.y;
	else
		return a.x < b.x;
}

bool operator == (const Pt & a, const Pt & b){
	return equal(a.x, b.x) && equal(a.y, b.y);
}

inline double operator * (const Pt & a, const Pt & b){
	return a.x * b.y - a.y * b.x;
}

inline double operator % (const Pt & a, const Pt & b){
	return a.x * b.x + a.y * b.y;
}

inline Pt operator - (const Pt & a, const Pt & b){
	return (Pt){a.x - b.x, a.y - b.y};
}

inline Pt operator + (const Pt & a, const Pt & b){
	return (Pt){a.x + b.x, a.y + b.y};
}

inline Pt operator * (double u, const Pt & a){
	return (Pt){a.x * u, a.y * u};
}

double sqr(double x){
	return x * x;
}

inline double len(const Pt & a){
	return sqrt(sqr(a.x) + sqr(a.y));
}

vector<Pt> convex_hull(vector<Pt> u){
    sort(u.begin(),u.end()); 
    u.erase(unique(u.begin(),u.end()),u.end()); 
    if(u.size()<3) return u;
    vector<Pt> c;
    for(size_t i=0,o=1,m=1;~i;i+=o){
        while(c.size()>m){
            Pt a=c.back()-c[c.size()-2];
            Pt b=c.back()-u[i];
            if(a*b<0) break; 
            c.pop_back();
        }
        c.push_back(u[i]);
        if(i+1==u.size()) m=c.size(),o=-1;
    }
    c.pop_back();
    return c;
}

double __cs, __sn;

Pt rotate(const Pt & a){
	return (Pt){a.x * __cs - a.y * __sn,
				a.x * __sn + a.y * __cs};
}

Pt rotate(const Pt & a, double s){
	return (Pt){a.x * cos(s) - a.y * sin(s),
				a.x * sin(s) + a.y * cos(s)};
}

double f[MAXN];
Pt p[MAXN], nico[MAXN];
int n;

void solve(){
	if (n <= 4){
		puts("No solution");
		return ;
	}
	for (int _ = 1; _ <= 1000000; _++){
		p[0] = (Pt){252.25252, 0};
		double s = (acos(-1.0) * 2.0 / n);
		//__cs = cos(s), __sn = sin(s);
		for (int i = 1; i < n; i++){
			p[i] = rotate(p[0], (acos(-1.0) * 2.0 / n * i));
		}
		for (int i = 0; i < n; i++){
			double x = rand() * 0.5 / RAND_MAX + 0.5;
			f[i] = x;
			p[i] = x * p[i];
		}
		sort(f, f + n);
		double ppp = 1e200;
		for (int i = 1; i < n; i++)
			ppp = min(ppp, f[i] - f[i-1]);
		//printf("%.15f\n", ppp * 252.25252);
		nico[0] = (Pt){0, 0};
		for (int i = 1; i < n - 1; i++){
			nico[i] = nico[i-1] + p[i];
		}
		if (nico[n - 2].y <= 0) continue;
		nico[n - 1].y = 0;
		nico[n - 1].x = nico[n - 2].x - (nico[n - 2].y / p[n - 1].y * p[n - 1].x);
		if (nico[n - 1].x >= 0) continue;
		nico[n] = nico[0];
		for (int i = 0; i < n; i++)
			f[i] = len(nico[i + 1] - nico[i]);
		sort(f, f + n);
		ppp = 1e200;
		for (int i = 1; i < n; i++)
			ppp = min(ppp, f[i] - f[i-1]);
		if (f[n - 1] > 999)
		    continue;
		if (ppp >= 5e-3){
			for (int i = 0; i < n; i++)
				printf("%.15f %.15f\n", nico[i].x, nico[i].y);
			return ;
		}
	}
	puts("No solution");
}

void printans(){

}

int main(){
	srand(time(NULL));
	int T = 1;
	//scanf("%d", &T);
	while(scanf("%d", &n) != EOF){
		solve();
		printans();
	}
	return 0;
}