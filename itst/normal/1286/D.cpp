#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; bool f = 0; char c = getchar(); while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return f ? -a : a;
}

const int _ = 1e5 + 7 , P = 998244353;
int poww(long long a , int b){int tms = 1; while(b){if(b & 1) tms = tms * a % P; a = a * a % P; b >>= 1;} return tms;}
int X[_] , Pr[_] , V[_] , N , iv100;

#define mid ((l + r) >> 1)
#define lch (x << 1)
#define rch (x << 1 | 1)
struct dat{int pwl , pwr , sum;}tr[_ << 2];
dat operator +(dat p , dat q){
	dat x; x.pwl = 1ll * p.pwl * q.pwl % P; x.pwr = 1ll * p.pwr * q.pwr % P;
	x.sum = (1ll * p.sum * q.pwr + 1ll * p.pwl * q.sum - 1ll * p.pwl * q.pwr % P + P) % P; return x;
}
void init(int x , int l , int r){
	if(l == r){tr[x].pwr = 1ll * Pr[l] * iv100 % P; tr[x].pwl = (1 - tr[x].pwr + P) % P; tr[x].sum = 1; return;}
	init(lch , l , mid); init(rch , mid + 1 , r); tr[x] = tr[lch] + tr[rch];
}
dat qry(int x , int l , int r , int L , int R){
	if(L > R) return (dat){1 , 1 , 1};
	if(l >= L && r <= R) return tr[x];
	dat cur = (dat){1 , 1 , 1}; if(mid >= L) cur = qry(lch , l , mid , L , R);
	if(mid < R) cur = cur + qry(rch , mid + 1 , r , L , R);
	return cur;
}

int fa[_] , rht[_] , bound[_][2]; int find(int x){return fa[x] == x ? x : (fa[x] = find(fa[x]));}
int calc(int rt){
	int L = max(bound[rt][0] , rt - 1) , R = min(bound[rt][1] , rht[rt] + 1); if(L + 1 > R) return 0;
	dat l = qry(1 , 1 , N , rt , L) , m = qry(1 , 1 , N , L + 1 , R - 1) , r = qry(1 , 1 , N , R , rht[rt]);
	return 1ll * m.sum * l.pwl % P * r.pwr % P;
}

int main(){
	N = read(); iv100 = poww(100 , P - 2); for(int i = 1 ; i <= N ; ++i){X[i] = read(); V[i] = read(); Pr[i] = read();}
	init(1 , 1 , N); for(int i = 1 ; i <= N ; ++i){fa[i] = rht[i] = i; bound[i][0] = 0; bound[i][1] = 1e9;}
	vector < pair < double , int > > hit;
	for(int i = 1 ; i < N ; ++i){
		hit.push_back(make_pair(1.0 * (X[i + 1] - X[i]) / (V[i] + V[i + 1]) , i));
		if(V[i] != V[i + 1]) hit.push_back(make_pair(1.0 * (X[i + 1] - X[i]) / abs(V[i] - V[i + 1]) , i));
	}
	sort(hit.begin() , hit.end()); int pre = 0 , ans = 0 , prb = 1;
	for(auto t : hit){
		int p = t.second , val = 1ll * (X[p + 1] - X[p]) * poww(fa[p + 1] == p + 1 ? V[p] + V[p + 1] : abs(V[p] - V[p + 1]) , P - 2) % P;
		ans = (ans + 1ll * prb * (val - pre + P)) % P; pre = val; int r = find(p);
		if(fa[p + 1] == p + 1){
			prb = 1ll * prb * poww(1ll * calc(r) * calc(p + 1) % P , P - 2) % P;
			fa[p + 1] = r; rht[r] = rht[p + 1]; bound[r][0] = max(bound[r][0] , bound[p + 1][0]); bound[r][1] = min(bound[r][1] , bound[p + 1][1]);
		}else{
			prb = 1ll * prb * poww(calc(r) , P - 2) % P;
			(V[p] < V[p + 1] ? bound[r][1] = min(bound[r][1] , p + 1) : bound[r][0] = max(bound[r][0] , p));
		}
		prb = 1ll * prb * calc(find(p)) % P;
	}
	cout << (ans - 1ll * prb * pre % P + P) % P;
	return 0;
}