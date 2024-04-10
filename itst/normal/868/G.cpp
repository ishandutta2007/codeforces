#include<bits/stdc++.h>
using namespace std;

const int P = 1e9 + 7; int poww(long long a , int b){int tms = 1 ; while(b){if(b & 1) tms = tms * a % P; a = a * a % P; b >>= 1;} return tms;}
struct poly{int k , b; poly(int _k = 0 , int _b = 0) : k(_k) , b(_b){}};
poly operator +(poly p , poly q){return poly((p.k + q.k) % P , (p.b + q.b) % P);}
poly val(poly p , poly q){return poly(1ll * p.k * q.k % P , (1ll * p.k * q.b + p.b) % P);}
int val(poly p , int q){return (1ll * p.k * q + p.b) % P;}
poly pw(poly p , int q){if(q){poly t = pw(p , q >> 1); t = val(t , t); return q & 1 ? val(p , t) : t;} return poly(1 , 0);}
poly pwsum(poly p , int q){
	if(q < 0) return poly(-1 , 0);
	static poly pw; if(!q) return poly(); else if(q == 1) return pw = p;
	poly cur = pwsum(p , q >> 1); cur = cur + poly(1ll * cur.k * pw.k % P , (1ll * cur.b * pw.k + 1ll * pw.b * (q >> 1)) % P);
	pw = val(pw , pw); if(q & 1){pw = val(p , pw); cur = cur + pw;} return cur;
}

int solve(int N , int K , poly A , poly B , poly SA , poly SB , bool flg){
	if(!K) return !flg ? val(SB , 1ll * B.b * poww(P + 1 - B.k , P - 2) % P) : val(SA , 1ll * A.b * poww(P + 1 - A.k , P - 2) % P);
	poly pwa = pwsum(A , N / K - 1) + poly(1 , 0) ,
		SA1 = poly(1ll * pwa.k * SA.k % P , (1ll * pwa.b * SA.k + 1ll * SA.b * (N / K)) % P) + val(SB , pw(A , N / K));
	poly pwb = pwsum(A , N / K - 2) + poly(1 , 0) ,
		SB1 = poly(1ll * pwb.k * SA.k % P , (1ll * pwb.b * SA.k + 1ll * SA.b * (N / K - 1)) % P) + val(SB , pw(A , N / K - 1));
	return solve(K , N % K , val(B , pw(A , N / K - 1)) , val(B , pw(A , N / K)) , SB1 , SA1 , 1);
}

int main(){
	int N , K , T;
	for(cin >> T ; T ; --T){
		cin >> N >> K; int t = __gcd(N , K); N /= t; K /= t;
		cout << 1ll * solve(N , K % N , poly(1 , 1) , poly((P + 1) / 2 , 1) , poly(1 , 0) , poly(1 , 0) , 0) * poww(N , P - 2) % P << endl;
	}
	return 0;
}