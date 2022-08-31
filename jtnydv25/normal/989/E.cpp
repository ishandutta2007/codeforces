#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ld double
#define ll long long
const ld eps = 1e-8;
inline ld add(ld x, ld y){ return x + y;}
inline ld sub(ld x, ld y){ return x - y;}
inline ld mul(ld x, ld y){ return x * y;}
inline ld inv(ld a){ return 1./a;}
inline bool double_equal(ld a, ld b){ return abs(a - b) <= eps;}
const int N = 205;
struct matrix{
    ld B[N][N], n;
    matrix(){n = N; memset(B,0,sizeof B);}
    matrix(int _n){
        n = _n; memset(B, 0, sizeof B);
    }
    void iden(){for(int i = 0; i < n; i++) B[i][i] = 1;}
    void operator += (matrix M){
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) B[i][j] = add(B[i][j], M.B[i][j]);
    }
    void operator -= (matrix M){
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) B[i][j] = sub(B[i][j], M.B[i][j]);
    }
    void operator *= (ld b){
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) B[i][j] = mul(b, B[i][j]);
    }
    matrix operator - (matrix M){
        matrix ret = (*this); ret -= M; return ret;
    }
    matrix operator + (matrix M){
        matrix ret = (*this); ret += M; return ret;
    }   
    matrix operator * (matrix M){
        matrix ret = matrix(n); memset(ret.B, 0, sizeof ret.B);
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < n;j++)
                for(int k = 0; k < n; k++){
                    ret.B[i][j] = add(ret.B[i][j], mul(B[i][k], M.B[k][j]));
                }
        return ret;
    }
    matrix operator *= (matrix M){ *this = ((*this) * M);}
    matrix operator * (int b){
        matrix ret  = (*this); ret *= b; return ret;
    }
    vector<double> multiply(const vector<double> & v) const{
    	vector<double> ret(n);
    	for(int i = 0; i < n; i++)
    		for(int j = 0; j < n; j++){
    			ret[i] += B[i][j] * v[j];
    		}
    	return ret;
    }
};

vector<vector<int> > con[N];

pair<int, int> get(int x, int y){
	int g = __gcd(abs(x), abs(y));
	x /= g; y /= g;
	if(x < 0){
		x *= -1; y *= -1;
	}
	if(x == 0 && y < 0) y *= -1;
	return {x, y};
}

int x[N], y[N];

map<pair<int, int>, vector<int> > partit;

matrix powers[20];

vector<double> get(int j, int m, int n){
	vector<double> v(n);
	v[j] = 1.;
	for(int i = 0; i < 20; i++) if(m >> i & 1) v = powers[i].multiply(v);
	return v;
}

int main(){
	int n = 200;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		x[i] = rand() % 20000, y[i] = rand() % 20000;
		scanf("%d %d", x + i, y + i);
	}
	matrix T = matrix(n);
	for(int i = 0; i < n; i++){
		partit.clear();
		for(int j = 0; j < n; j++) if(i != j){
			partit[get(x[j] - x[i], y[j] - y[i])].push_back(j);
		}
		double sm = 0;
		int lines = partit.size();
		for(auto it : partit){
			con[i].push_back(it.S);
			double total = it.S.size() + 1;
			for(auto j : it.S) T.B[i][j] = 1. / total / lines, sm += 1. / total / lines;
		}
		T.B[i][i] = 1. - sm;
	}
	powers[0] = T;
	for(int i = 1; i < 20; i++) powers[i] = powers[i - 1] * powers[i - 1];
	int q = 200;
	scanf("%d", &q);
	while(q--){
		int t = rand() % n, m = rand() % 10000 + 1;
		scanf("%d %d", &t, &m); t--; m--;
		vector<double> v = get(t, m, n);
		double ans = 0;
		for(int i = 0; i < n; i++){
			for(auto it : con[i]){
				double sm = v[i];
				for(int j : it){
					sm += v[j];
				}
				sm /= it.size() + 1.;
				ans = max(ans, sm);
			}
		}
		printf("%.17lf\n", ans);
	}
}