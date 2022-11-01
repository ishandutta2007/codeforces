#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair < int , int >
const int P = 1e9 + 7; map < int , pii > dat[103]; int N;
int poww(int a , int b){int tms = 1; while(b){if(b & 1) tms = tms * a % P; a = a * a % P; b >>= 1;} return tms;}
void exgcd(int a , int b , int &x , int &y){!b ? (x = 1 , y = 0) : (exgcd(b , a % b , y , x) , y -= a / b * x);}
int qiv(int a , int c){int x , y; exgcd(a , c , x , y); return x < 0 ? x + c : x;}

pii merge(pii p , pii q){//ap * x_p + bp = aq * x_q + bq
	int v = __gcd(p.first , q.first);
	if(!v) if(p.first != q.first){cout << -1; exit(0);} else return p;
	if((q.second - p.second) % v){cout << -1; exit(0);}
	if(!p.first) return p; else if(!q.first) return q;
	int x , y; exgcd(p.first , q.first , x , y);
	x *= (q.second - p.second) / v; y *= (q.second - p.second) / v;

	int lim = max(0ll , max((-x + q.first / v - 1) / (q.first / v) , (y + p.first / v - 1) / (p.first / v)));
	x += lim * q.first / v; y -= lim * p.first / v;
	lim = min(x / (q.first / v) , -y / (p.first / v));
	x -= lim * q.first / v; y += lim * p.first / v;
	
	return pii(p.first * q.first / v , p.first * x + p.second);
}

int C , A , B , X , Y;
void addeq(pii p , pii q){//get c * y = a * x + b -> get the solution.
	int c = q.first , a = p.first , b = p.second - q.second;
	if(!a && !c) if(!b) return; else{cout << -1; exit(0);}
	int v = __gcd(a , c); if(b % v){cout << -1; exit(0);}
	c /= v; a /= v; b /= v;
	if(!c) if(b > 0 || (~X && X != -b)){cout << -1; exit(0);} else X = -b;
	else if(!a) if(b < 0 || (~Y && Y != b)){cout << -1; exit(0);} else Y = b;
	else
		if(C && (C != c || B != b || A != a)){
			int a1 = A * c - C * a , b1 = C * b - B * c;
			if(!a1 || (long double)a1 * b1 < 0 || b1 % a1 || (~X && X != b1 / a1)){cout << -1; exit(0);}
			X = b1 / a1;
		}else{C = c; B = b; A = a;}
}

pii solve(map < int , pii > p , map < int , pii > q){
	A = B = C = 0; X = Y = -1;
	for(auto t : p) addeq(t.second , q[t.first]);
	for(auto t : q) addeq(p[t.first] , t.second);
	if(C && ~X && ~Y && C * Y != A * X + B){cout << -1; exit(0);}
	if(C && ~Y)
		if(C * Y - B < 0 || (C * Y - B) % A){cout << -1; exit(0);}
		else X = (C * Y - B) / A;
	if(~X) return pii(0 , X);
	if(!C) return pii(1 , 0);
	int nd = (C - B) * qiv(A , C) % C;
	if(nd * A + B < 0) nd += (-B - nd * A + A * C - 1) / (A * C) * C;
	return make_pair(C , nd);
}

signed main(){
	cin >> N;
	for(int i = 1 ; i <= N ; ++i){
		int A , B; cin >> A >> B;
		for(int j = 2 ; j * j <= A ; ++j) while(!(A % j)){++dat[i][j].second; A /= j;}
		if(A != 1) ++dat[i][A].second;
		for(int j = 2 ; j * j <= B ; ++j) while(!(B % j)){++dat[i][j].first; B /= j;}
		if(B != 1) ++dat[i][B].first;
	}
	pii ans(1 , 0); for(int i = 2 ; i <= N ; ++i) ans = merge(ans , solve(dat[1] , dat[i]));
	int tms = 1; for(auto t : dat[1]) tms = 1ll * tms * poww(t.first , t.second.first * ans.second + t.second.second) % P;
	cout << tms; return 0;
}