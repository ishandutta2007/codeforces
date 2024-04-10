#include<bits/stdc++.h>
#define ld long double
//This code is written by Itst
using namespace std;

struct vec{
	ld x , y;
	vec(ld _x , ld _y){x = _x; y = _y;}
	ld len(){return sqrt(x * x + y * y);}
};
ld X[3] , Y[3] , x , y , R;
const ld eps = 1e-2;

void input(){
	cin >> X[0] >> Y[0] >> X[1] >> Y[1] >> X[2] >> Y[2];
}

inline void calc(int x , int y , ld &A , ld &B , ld &C){
	A = 2 * (X[y] - X[x]);
	B = 2 * (Y[y] - Y[x]);
	C = X[x] * X[x] + Y[x] * Y[x] - X[y] * X[y] - Y[y] * Y[y];
}

ld gcd(ld a , ld b){
	while(a > eps && b > eps)
		a > b ? a -= b : b -= a;
	return a + b;
}

ld dot(vec a , vec b){
	return a.x * b.x + a.y * b.y;
}

ld calc(int a , int b){
	return acos(dot(vec(x - X[a] , y - Y[a]) , vec(x - X[b] , y - Y[b])) / R / R + 1e-12);
}

void work(){
	ld A1 , B1 , C1 , A2 , B2 , C2;
	calc(0 , 1 , A1 , B1 , C1);
	calc(1 , 2 , A2 , B2 , C2);
	x = (C2 * B1 - C1 * B2) / (A1 * B2 - A2 * B1);
	y = (C1 * A2 - C2 * A1) / (A1 * B2 - A2 * B1);
	R = vec(x - X[0] , y - Y[0]).len();
	ld t1 = calc(0 , 2) , t2 = calc(1 , 2);
	ld ans = gcd(2 * acos(-1) - t1 - t2 , gcd(t1 , t2));
	cout << fixed << setprecision(10) << 2 * acos(-1) / ans * R * R * sin(ans) / 2;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in" , "r" , stdin);
	//freopen("out" , "w" , stdout);
#endif
	input();
	work();
	return 0;
}