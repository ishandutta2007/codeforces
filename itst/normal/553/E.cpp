#include<vector>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<stdio.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

#define ld double
const ld pi = acos(-1);
struct comp{
	ld x , y;
	comp(ld _x = 0 , ld _y = 0) : x(_x) , y(_y){}
	friend comp operator +(comp x , comp y){return comp(x.x + y.x , x.y + y.y);}
	friend comp operator -(comp x , comp y){return comp(x.x - y.x , x.y - y.y);}
	friend comp operator *(comp x , comp y){return comp(x.x * y.x - x.y * y.y , x.y * y.x + x.x * y.y);}
	friend comp operator /(comp x , ld y){return comp(x.x / y , x.y / y);}
};

const int _ = 1 << 15;
int dir[_] , need; comp w[_];
void init(int len){
	need = 1; while(need < len) need <<= 1;
	for(int i = 1 ; i < need ; ++i) dir[i] = (dir[i >> 1] >> 1) | (i & 1 ? need >> 1 : 0);
	static int L = 1;
	for(int &i = L ; i < need ; i <<= 1){
		w[i] = comp(1 , 0); comp wn(cos(pi / i) , sin(pi / i));
		for(int j = 1 ; j < i ; ++j) w[i + j] = w[i + j - 1] * wn;
	}
}

void DFT(comp *arr , int tp){
	for(int i = 0 ; i < need ; ++i) if(i < dir[i]) swap(arr[i] , arr[dir[i]]);
	for(int i = 1 ; i < need ; i <<= 1)
		for(int j = 0 ; j < need ; j += i << 1)
			for(int k = 0 ; k < i ; ++k){
				comp x = arr[j + k] , y = arr[i + j + k] * w[i + k];
				arr[j + k] = x + y; arr[i + j + k] = x - y;
			}
	if(tp == -1){
		reverse(arr + 1 , arr + need);
		for(int i = 0 ; i < need ; ++i) arr[i] = arr[i] / need;
	}
}

int N , M , t , x , S[103] , T[103] , W[103] , dist[53];
ld ans[53][_] , tmp[103][_] , tms[103][_] , sum[103][_]; comp pot[53][_];
void divide(int l , int r){
	if(l == r){
		for(int i = 1 ; i < N ; ++i) ans[i][l] = 1e60;
		for(int i = 1 ; i <= M ; ++i)
			ans[S[i]][l] = min(ans[S[i]][l] , tmp[i][l] + W[i] + (x + dist[T[i]]) * sum[i][t + 1 - l]);
		return;
	}
	int mid = (l + r) >> 1; divide(mid + 1 , r); init(r - l);
	for(int p = 1 ; p < N ; ++p){
		memset(&pot[p] , 0 , sizeof(comp) * need);
		for(int i = mid + 1 ; i <= r ; ++i) pot[p][i - mid - 1].x = ans[p][i];
		DFT(pot[p] , 1);
	}
	for(int p = 1 ; p <= M ; ++p){
		memset(&pot[0] , 0 , sizeof(comp) * need);
		for(int i = 0 ; i < r - l ; ++i) pot[0][i] = tms[p][r - l - i]; 
		DFT(pot[0] , 1); for(int i = 0 ; i < need ; ++i) pot[0][i] = pot[0][i] * pot[T[p]][i];
		DFT(pot[0] , -1); for(int i = l ; i <= mid ; ++i) tmp[p][i] += pot[0][r - mid - 1 + i - l].x;
	}
	divide(l , mid);
}

int main(){
	N = read(); M = read(); t = read(); x = read();
	for(int i = 1 ; i < N ; ++i) dist[i] = 1e9;
	for(int i = 1 ; i <= M ; ++i){S[i] = read(); T[i] = read(); W[i] = read(); for(int j = 1 ; j <= t ; ++j) tms[i][j] = read();}
	for(int i = 1 ; i <= N ; ++i) for(int j = 1 ; j <= M ; ++j) dist[S[j]] = min(dist[S[j]] , dist[T[j]] + W[j]);
	for(int i = 1 ; i <= M ; ++i) for(int j = t ; j ; --j) sum[i][j] = sum[i][j + 1] + (tms[i][j] /= 1e5);
	divide(0 , t); printf("%.9lf\n" , ans[1][0]); return 0;
}