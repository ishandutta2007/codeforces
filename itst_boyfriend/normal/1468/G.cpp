#include<bits/stdc++.h>
using namespace std;

int read(){
	int a= 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

#define ld double
struct comp{
	ld x , y; comp(ld _x = 0 , ld _y = 0) : x(_x) , y(_y){}
	friend comp operator +(comp p , comp q){return comp(p.x + q.x , p.y + q.y);}
	friend comp operator -(comp p , comp q){return comp(p.x - q.x , p.y - q.y);}
	friend ld operator *(comp p , comp q){return p.x * q.x + p.y * q.y;}
	friend comp operator *(comp p , ld q){return comp(p.x * q , p.y * q);}
	friend ld operator %(comp p , comp q){return p.x * q.y - p.y * q.x;}
	friend ld len(comp p){return sqrt(p.x * p.x + p.y * p.y);}
}val[200003]; int N , H;
struct line{
	comp s , t; line(comp _s = comp() , comp _t = comp()) : s(_s) , t(_t){}
	friend comp sect(line p , line q){
		ld scale = ((p.t - p.s) % (q.t - p.s)) / ((p.t - p.s) % (q.t - q.s));
		return q.t - (q.t - q.s) * scale;
	}
};

int main(){
	N = read(); H = read(); for(int i = 1 ; i <= N ; ++i){val[i].x = read(); val[i].y = read();}
	comp high = val[N] + comp(0 , H) , dir = val[N - 1]; ld ans = len(val[N] - val[N - 1]);
	for(int i = N - 2 ; i ; --i)
		if(fabs((high - dir) % (val[i + 1] - val[i])) > 1e-9){
			ld f2 = (val[i] - high) % (dir - high);
		    comp s = sect(line(val[i] , val[i + 1]) , line(high , dir));
			if(f2 > 0){ans += len(s - val[i]); dir = val[i];}
		}else if(fabs(((high - dir) % (high - val[i]))) < 1e-9) ans += len(val[i + 1] - val[i]);
	cout << fixed << setprecision(10) << ans; return 0;
}