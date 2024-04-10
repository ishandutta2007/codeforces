#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar();
	while(!isdigit(c)) c = getchar();
	while(isdigit(c)){
		a = a * 10 + c - 48;c = getchar();
	}
	return a;
}

int gcd(int p , int q){
	int r = p % q;
	while(r){p = q; q = r; r = p % q;}
	return q;
}

const int _ = 5e5 + 7;
int Gcd[_ << 2] , N , M;
#define mid ((l + r) >> 1)
#define lch (x << 1)
#define rch (x << 1 | 1)

void up(int x){Gcd[x] = gcd(Gcd[lch] , Gcd[rch]);}

void init(int x , int l , int r){
	if(l == r) Gcd[x] = read();
	else{init(lch , l , mid); init(rch , mid + 1 , r); up(x);}
}

void modify(int x , int l , int r , int tar , int val){
	if(l == r) Gcd[x] = val;
	else{
		mid >= tar ? modify(lch , l , mid , tar , val) : modify(rch , mid + 1 , r , tar , val);
		up(x);
	}
}

void qry(int x , int l , int r , int L , int R , int val , int &cnt){
	if(Gcd[x] % val == 0) return;
	if(l == r){++cnt; return;}
	if(mid >= L) qry(lch , l , mid , L , R , val , cnt);
	if(cnt < 2 && mid < R) qry(rch , mid + 1 , r , L , R , val , cnt);
}

int main(){
	N = read(); init(1 , 1 , N);
	for(M = read() ; M ; --M)
		if(read() == 1){
			int l = read() , r = read() , val = read() , cnt = 0;
			qry(1 , 1 , N , l , r , val , cnt);
			puts(cnt < 2 ? "YES" : "NO");
		}
		else{
			int x = read() , val = read();
			modify(1 , 1 , N , x , val);
		}
	return 0;
}