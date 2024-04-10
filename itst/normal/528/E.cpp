// luogu-judger-enable-o2
#include<bits/stdc++.h>
//this code is written by Itst
using namespace std;

#define ld long double
struct vec{
	ld x , y;
	vec(ld _x = 0 , ld _y = 0) : x(_x) , y(_y){}
	vec operator +(vec a){return vec(x + a.x , y + a.y);}
	vec operator -(vec a){return vec(x - a.x , y - a.y);}
	ld operator *(vec a){return x * a.x + y * a.y;}
	ld operator %(vec a){return x * a.y - y * a.x;}
};
struct line{
	int a , b , c; ld k;
	line(int _a = 0 , int _b = 0 , int _c = 0) : a(_a) , b(_b) , c(_c){k = _b == 0 ? 1e60 : -_a * 1.0 / _b;}
	friend bool operator <(line A , line B){return A.k < B.k;}
	friend vec sect(line A , line B){
		return vec((B.b * A.c - B.c * A.b) * 1.0 / (A.a * B.b - A.b * B.a) , (B.c * A.a - B.a * A.c) * 1.0 / (A.a * B.b - A.b * B.a));
	}
}now[3003];
int N;

signed main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	cin >> N;
	for(int i = 1 ; i <= N ; ++i){
		int a , b , c; cin >> a >> b >> c; now[i] = line(a , b , c);
	}
	sort(now + 1 , now + N + 1);
	ld ans = 0;
	for(int i = 1 ; i <= N ; ++i){
		vec sum;
		for(int j = i + 1 ; j <= N ; ++j){
			vec tmp = sect(now[i] , now[j]); ans += sum % tmp;
			sum = sum + tmp;
		}
		for(int j = 1 ; j < i ; ++j){
			vec tmp = sect(now[i] , now[j]); ans += sum % tmp;
			sum = sum + tmp;
		}
	}
	cout << ans * 3 / N / (N - 1) / (N - 2);
	return 0;
}