#include<bits/stdc++.h>
using namespace std;

#define int long long
int read(){
	int a = 0; char c = getchar(); bool f = 0; while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return f ? -a : a;
}

const int P = 1e9 + 7 , _ = 1e6 + 7;
struct vec{
	int x , y;
	vec(int _x = 0 , int _y = 0) : x(_x ) , y(_y){}
	friend vec operator +(vec p , vec q){return vec(p.x + q.x , p.y + q.y);}
	friend vec operator -(vec p , vec q){return vec(p.x - q.x , p.y - q.y);}
	friend int operator *(vec p , vec q){return p.x * q.x + p.y * q.y;}
	friend int operator %(vec p , vec q){return p.x * q.y - p.y * q.x;}
}now[_]; int N , ans , area , s1[_] , s2[_] , sx[_] , sy[_];

int S(vec p , vec q , vec r){return abs((p - r) % (q - r));}

signed main(){
	N = read(); for(int i = 1 ; i <= N ; ++i){now[i].x = read(); now[i].y = read(); now[i + N] = now[i];}
	for(int i = 2 ; i < N ; ++i) area += S(now[i] , now[i + 1] , now[1]);
    int pos = 2 , curs = 0;
	for(int i = 1 ; i <= 2 * N ; ++i){
		int val = (now[i] % now[i - 1] % P + P) % P;
		s1[i] = (s1[i - 1] + val) % P; s2[i] = (s2[i - 1] + val * i) % P;
		sx[i] = (sx[i - 1] + now[i].x + P) % P;
		sy[i] = (sy[i - 1] + now[i].y + P) % P;
	}
	for(int i = 1 ; i <= N ; ++i){
		while(curs + S(now[pos + 1] , now[pos] , now[i]) <= area / 2){
			curs += S(now[pos + 1] , now[pos] , now[i]); ++pos;
		}

		int val = 0 , l = i + 1 , r = pos , cnt = r - l;
		val = (val + (s1[r] - s1[l] + P) * (r + 1) - (s2[r] - s2[l]) + P) % P;
		val = (val + now[i].x * (sy[r] - sy[l] - cnt * now[l].y % P + 2 * P) % P + P) % P;
		val = (val + now[i].y * (cnt * now[l].x % P - (sx[r] - sx[l]) + P) % P + P) % P;

		l = pos + 1; r = i + N - 1; cnt = r - l;
		val = (val + (s2[r] - s2[l]) - (s1[r] - s1[l] + P) * l % P + P) % P;
		val = (val + now[i].x * (cnt * now[r].y % P - (sy[r - 1] - sy[l - 1]) + P) % P + P) % P;
		val = (val + now[i].y * (sx[r - 1] - sx[l - 1] - cnt * now[r].x % P + 2 * P) % P + P) % P;

		ans = (ans + area % P * (N - 3) - 2 * val + 2 * P) % P;
		
		curs -= S(now[pos] , now[i] , now[i + 1]);
	}
	cout << ans * ((P + 1) / 2) % P; return 0;
}