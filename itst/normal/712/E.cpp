#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

#define ld long double
#define mid ((l + r) >> 1)
#define lch (x << 1)
#define rch (x << 1 | 1)
const int _ = 4e5 + 7;
struct data{
	ld ll , lr , rl , rr; data(){lr = rl = 1; ll = rr = 0;}
	friend data operator +(data p , data q){
		data x; x.lr = p.lr * q.lr / (1 - p.rr * q.ll); x.rl = q.rl * p.rl / (1 - q.ll * p.rr);
		x.ll = p.ll + p.lr * p.rl * q.ll / (1 - p.rr * q.ll);
		x.rr = q.rr + q.rl * q.lr * p.rr / (1 - p.rr * q.ll);
		return x;
	}
}now[_ << 2];

void modify(int x , int l , int r , int tar , ld val){
	if(l == r){now[x].lr = now[x].rr = val; now[x].ll = now[x].rl = 1 - val; return;}
	mid >= tar ? modify(lch , l , mid , tar , val) : modify(rch , mid + 1 , r , tar , val);
	now[x] = now[lch] + now[rch];
}

data qry(int x , int l , int r , int L , int R){
	if(l >= L && r <= R) return now[x];
	data sum; if(mid >= L) sum = qry(lch , l , mid , L , R);
	if(mid < R) sum = sum + qry(rch , mid + 1 , r , L , R);
	return sum;
}

int main(){
	int N = read() , Q = read();
	for(int i = 1 ; i <= N ; ++i){int a = read() , b = read(); modify(1 , 1 , N , i , 1.0 * a / b);}
	while(Q--)
		if(read() == 1){int i = read() , a = read() , b = read(); modify(1 , 1 , N , i , 1.0 * a / b);}
		else{int l = read() , r = read(); cout << fixed << setprecision(10) << qry(1 , 1 , N , l , r).lr << endl;}
	return 0;
}