#include<bits/stdc++.h>
#define int long long
#define ld long double
//This code is written by Itst
using namespace std;

inline int read(){
	int a = 0;
	char c = getchar();
	bool f = 0;
	while(!isdigit(c) && c != EOF){
		if(c == '-')
			f = 1;
		c = getchar();
	}
	if(c == EOF)
		exit(0);
	while(isdigit(c)){
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar();
	}
	return f ? -a : a;
}

const int MAXN = 2010;
struct vec{
	int ind , x , y;
	vec(int _x = 0 , int _y = 0){x = _x; y = _y;}
	vec operator -(vec a){
		return vec(x - a.x , y - a.y);
	}
	bool operator <(const vec a)const{
		return x < a.x;
	}
}now[MAXN];
struct line{
	ld k , b;
	int x , y;
	line(ld _k = 0 , ld _b = 0){k = _k; b = _b;}
	bool operator <(const line a)const{
		return k < a.k;
	}
}cur[MAXN * MAXN];
int N , S , cnt , rk[MAXN];

void input(){
	N = read();
	S = read();
	for(int i = 1 ; i <= N ; ++i){
		now[i].x = read();
		now[i].y = read();
		now[i].ind = i;
	}
}

inline line calc(vec a , vec b){
	if(a.x == b.x)
		return line(1e50 , 0);
	else{
		ld k = (a.y - b.y) * 1.0 / (a.x - b.x);
		return line(k , a.y - a.x * k);
	}
}

void init(){
	for(int i = 1 ; i <= N ; ++i)
		for(int j = i + 1 ; j <= N ; ++j){
			cur[++cnt] = calc(now[i] , now[j]);
			cur[cnt].x = i;
			cur[cnt].y = j;
		}
	sort(cur + 1 , cur + cnt + 1);
	sort(now + 1 , now + N + 1);
	for(int i = 1 ; i <= N ; ++i)
		rk[now[i].ind] = i;
}

inline int abss(int x){
	return x < 0 ? -x : x;
}

inline int dot(vec a , vec b){
	return a.x * b.y - a.y * b.x;
}

inline ld calc(vec a , vec b , vec c){
	return abss(dot(c - a , b - a)) / 2.0;
}

inline bool cmp(ld a , ld b){
	return a - 1e-5 <= b && a + 1e-5 >= b;
}

#define mid ((L + R) >> 1)
inline void erf(int L , int R , vec p , vec q , bool type){
	while(L < R){
		long double t = calc(now[mid] , p , q);
		if(cmp(t , S)){
			cout << "Yes" << endl << now[mid].x << ' ' << now[mid].y << endl << p.x << ' ' << p.y << endl << q.x << ' ' << q.y << endl;
			exit(0);
		}
		(t > S) ^ type ? L = mid + 1 : R = mid - 1;
	}
	if(cmp(calc(now[L] , p , q) , S)){
		cout << "Yes" << endl << now[L].x << ' ' << now[L].y << endl << p.x << ' ' << p.y << endl << q.x << ' ' << q.y << endl;
		exit(0);
	}
	if(cmp(calc(now[R] , p , q) , S)){
		cout << "Yes" << endl << now[R].x << ' ' << now[R].y << endl << p.x << ' ' << p.y << endl << q.x << ' ' << q.y << endl;
		exit(0);
	}
}

void work(){
	for(int i = 1 ; i <= cnt ; ++i){
		int p = cur[i].x , q = cur[i].y;
		if(rk[p] > rk[q])
			swap(p , q);
		erf(1 , rk[p] - 1 , now[rk[p]] , now[rk[q]] , 0);
		erf(rk[q] + 1 , N , now[rk[p]] , now[rk[q]] , 1);
		swap(now[rk[p]] , now[rk[q]]);
		swap(rk[p] , rk[q]);
	}
	cout << "No";
}

signed main(){
	input();
	init();
	work();
	return 0;
}