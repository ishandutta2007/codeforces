#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const int MAXN = 1e5 + 10;
const double eps = 1e-11;

struct Pt{
	double x, y, z;
};

inline int equal(double p, double q){
	return fabs(p - q) < eps;
}

inline int sgn(double x){
	if (fabs(x) < eps)
		return 0;
	else
		if (x < 0) return -1;
		else return 1;
}

bool operator < (const Pt & a, const Pt & b){
	if (equal(a.x,b.x)){
		if (equal(a.y, b.y))
			return a.z < b.z;
		else
			return a.y < b.y;
	}
	else
		return a.x < b.x;
}

bool operator == (const Pt & a, const Pt & b){
	return equal(a.x, b.x) && equal(a.y, b.y) && equal(a.z, b.z);
}

inline Pt operator * (const Pt & a, const Pt & b){
	return (Pt){a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x};
}

inline double operator % (const Pt & a, const Pt & b){
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

inline Pt operator - (const Pt & a, const Pt & b){
	return (Pt){a.x - b.x, a.y - b.y, a.z - b.z};
}

inline Pt operator + (const Pt & a, const Pt & b){
	return (Pt){a.x + b.x, a.y + b.y, a.z + b.z};
}

inline Pt operator * (double u, const Pt & a){
	return (Pt){a.x * u, a.y * u, a.z * u};
}

inline Pt operator * (const Pt & a, double u){
	return (Pt){a.x * u, a.y * u, a.z * u};
}

inline Pt operator / (const Pt & a, double u){
	return (Pt){a.x / u, a.y / u, a.z / u};
}

inline double sqr(double x){
	return x * x;
}

inline double len(const Pt & a){
	return sqrt(sqr(a.x) + sqr(a.y) + sqr(a.z));
}

Pt resize(Pt a){
	double u = len(a);
	if (equal(u, 0.0)) return (Pt){0.0, 0.0, 0.0};
	else{return a / u;};
}

Pt norm(const Pt & u, const Pt & v, const Pt & w){
	return (v-u) * (w-u);
}

double dis_pt_pl(Pt p, Pt u, Pt v, Pt w){
	Pt n = resize((v - u) * (w - u));
	return fabs(n%(p-u));
}

double area_tri(Pt u, Pt v, Pt w){
	return fabs(len((v-u)  * (w-u))) / 2;
}

Pt a[MAXN], b[MAXN];
int n,m ;

int read(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%lf%lf%lf", &a[i].x, &a[i].y, &a[i].z);	
	a[0] = a[n];
	scanf("%d", &m);
	for(int i = 1; i <= m; i++)
		scanf("%lf%lf%lf", &b[i].x, &b[i].y, &b[i].z);	
	b[0] = b[m];
}

vector<Pt> E, F;
int f[MAXN], g[MAXN];
int Nico[MAXN * 2];

void solve(){
	Pt di = (b[3] - b[2]) * (b[1] - b[2]);
	for(int i = 1; i <= n; i++){
		f[i] = sgn((b[0] - a[i]) % di); 
	}
	f[0] = f[n];f[n+1] = f[1];
	E.clear();
	int pre = f[0];
	pre = f[n];
	for(int i = n; i; i--)
		if (f[i]){
			pre = f[i];
			break;
		}
	for(int i = 1; i <= n; i++)
		if (pre * f[i] == -1){
			double saki = (di.x * (b[1].x - a[i-1].x) + di.y * (b[1].y - a[i-1].y) + di.z * (b[1].z - a[i-1].z)) / (di.x * (a[i].x - a[i-1].x) + di.y * (a[i].y - a[i-1].y) + di.z * (a[i].z - a[i-1].z));
			Pt QAQ;
			QAQ.x = a[i-1].x + (a[i].x - a[i-1].x) * saki;
			QAQ.y = a[i-1].y + (a[i].y - a[i-1].y) * saki;
			QAQ.z = a[i-1].z + (a[i].z - a[i-1].z) * saki;
			E.push_back(QAQ);
			/*
			double high = 1, low = 0, mid;
			Pt Nico, Umi;
			Umi = a[i] - a[i-1];
			for(int _ = 1; _ <= 60; _++){
				mid = (high + low) / 2;
				Nico = a[i-1] + Umi * mid;
				if (sgn((b[0] - Nico) % di) == f[i])
					high = mid;
				else
					low = mid;
			}
			E.push_back(a[i-1] + Umi * ((high + low) / 2));*/
			pre = f[i];
		}
		else if (f[i] == 0){
			//if (f[i-1] * f[i+1] == -1 || (f[i-1] == 0 && f[i+1] != 0)) E.push_back(a[i]);
		}
	sort(E.begin(), E.end());
	
//	assert(E.size() % 2 == 0);
	
	di = (a[3] - a[2]) * (a[1] - a[2]);
	for(int i = 1; i <= m; i++){
		g[i] = sgn((a[0] - b[i]) % di); 
	}
	g[0] = g[m];g[m+1] = g[1];
	F.clear();
	pre = g[m];
	for(int i = m; i; i--)
		if (g[i]){
			pre = g[i];
			break;
		}
	for(int i = 1; i <= m; i++)
		if (pre * g[i] == -1){
			double saki = (di.x * (a[1].x - b[i-1].x) + di.y * (a[1].y - b[i-1].y) + di.z * (a[1].z - b[i-1].z)) / (di.x * (b[i].x - b[i-1].x) + di.y * (b[i].y - b[i-1].y) + di.z * (b[i].z - b[i-1].z));
			Pt QAQ;
			QAQ.x = b[i-1].x + (b[i].x - b[i-1].x) * saki;
			QAQ.y = b[i-1].y + (b[i].y - b[i-1].y) * saki;
			QAQ.z = b[i-1].z + (b[i].z - b[i-1].z) * saki;
			F.push_back(QAQ);
			/*
			double high = 1, low = 0, mid;
			Pt Nico, Umi;
			Umi = b[i] - b[i-1];
			for(int _ = 1; _ <= 60; _++){
				mid = (high + low) / 2;
				Nico = b[i-1] + Umi * mid;
				if (sgn((a[0] - Nico) % di) == g[i])
					high = mid;
				else
					low = mid;
			}
			F.push_back(b[i-1] + Umi * ((high + low) / 2));*/
			pre = g[i];
		}
		else if (g[i] == 0){
		//	if (g[i-1] * g[i+1] != 1) F.push_back(b[i]);
		}
	sort(F.begin(), F.end());
	
//	assert(F.size() % 2 == 0);
/*	
	for(int i = 1; i <= n; i++)
		cerr << f[i] << ' '; cerr<<endl;
	
	for(int i = 1; i <= m; i++)
		cerr << g[i] << ' '; cerr<<endl;
	
	for(int i = 0; i < E.size(); i++)
		cerr<<E[i].x<<' '<<E[i].y<<' '<<E[i].z<<endl;
		
	cerr<<endl;
	
	for(int i = 0; i < F.size(); i++)
		cerr<<F[i].x<<' '<<F[i].y<<' '<<F[i].z<<endl;
*/	
	//int flag1 = 0, flag2 = 0;
	int now = 0;
	int flag = 0;
	Nico[flag] = 23333333;
	
	int p = 0, q = 0;
	int i, j;
	for( i = 0, j = 0; i < E.size() && j < F.size(); ){
		if (F[j] < E[i]){
			j++; q = 1 - q;
			if (Nico[flag] == 2){
				flag--;
			}
			else{
				flag++;
				Nico[flag] = 2;
			}
		/*	if (q == 1){
				now = 2;
			}
			else{
				if (p == 1 && now == 1){
					flag1 = 1; break;
				}
			}*/
		}
		else{
			i++; p = 1 - p;
			if (Nico[flag] == 1){
				flag--;
			}
			else{
				flag++;
				Nico[flag] = 1;
			}
		/*	if (p == 1){
				now = 1;
			}
			else{
				if (q == 1 && now == 2){
					flag = 1; break;
				}
			}*/
		}
//		cerr<<i<<' '<<j<<' '<<flag<<endl;
		/*
		if (p && q){
			flag = 1;
			break;
		}*/
	}
	while(i < E.size()){
			if (Nico[flag] == 1){
				flag--;
			}
			else{
				flag++;
				Nico[flag] = 1;
			}
			i++;
	}
	while(j < F.size()){
			if (Nico[flag] == 2){
				flag--;
			}
			else{
				flag++;
				Nico[flag] = 2;
			}
			j++;
	}
//	cerr <<flag<<endl;
	
	puts(flag ? "YES" : "NO");
	
}

void printans(){

}

int main(){
	int T=1;
	while(T--){
		read(); 
		solve();
		printans();
	}
	return 0;
} 

/*


4
0 0 0
2 0 0
2 2 0
0 2 0
4
1 1 -1
1 1 1
1 3 1
1 3 -1

4
0 0 0
2 0 0
2 2 0
0 2 0
4
1 1 -1
1 1 1
3 3 1
3 3 -1


*/