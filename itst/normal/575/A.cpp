#include<bits/stdc++.h>
using namespace std;

#define int long long
int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

const int _ = 50003; int K , N , M , P , S[_]; map < int , int > sval;
struct mat{
	int arr[2][2]; mat(){memset(arr , 0 , sizeof(arr));} int* operator [](int x){return arr[x];}
	friend mat operator *(mat p , mat q){
		mat r; for(int i = 0 ; i < 2 ; ++i) for(int j = 0 ; j < 2 ; ++j) for(int k = 0 ; k < 2 ; ++k) r[i][k] += p[i][j] * q[j][k];
		for(int i = 0 ; i < 2 ; ++i) for(int j = 0 ; j < 2 ; ++j) r[i][j] %= P;
		return r;
	}
	friend mat operator ^(mat p , int q){mat tmp; tmp[0][0] = tmp[1][1] = 1; while(q){if(q & 1) tmp = tmp * p; p = p * p; q >>= 1;} return tmp;}
}tr[_ << 2];

#define mid ((l + r) >> 1)
#define lch (x << 1)
#define rch (x << 1 | 1)
void prep(int x , int l , int r){
	if(l == r){tr[x][1][0] = 1; tr[x][0][1] = S[(l + N - 2) % N]; tr[x][1][1] = S[(l + N - 1) % N]; return;}
	prep(lch , l , mid); prep(rch , mid + 1 , r); tr[x] = tr[lch] * tr[rch];
}

mat qry(int x , int l , int r , int L , int R){
	if(l >= L && r <= R) return tr[x];
	if(mid >= L && mid < R) return qry(lch , l ,mid , L , R) * qry(rch , mid + 1 , r , L , R);
	return mid < L ? qry(rch , mid + 1 , r , L , R) : qry(lch , l , mid , L , R);
}

mat qry(int l , int r){
	if(l > r){mat tmp; tmp[0][0] = tmp[1][1] = 1; return tmp;}
	if(l / N == r / N) return qry(1 , 0 , N - 1 , l % N , r % N);
	return qry(1 , 0 , N - 1 , l % N , N - 1) * (tr[1] ^ (r / N - l / N - 1)) * qry(1 , 0 , N - 1 , 0 , r % N);
}

signed main(){
	K = read(); P = read(); N = read(); for(int i = 0 ; i < N ; ++i) S[i] = read();
	M = read(); for(int i = 1 ; i <= M ; ++i){int j = read() , v = read(); sval[j] = v; sval.insert(make_pair(j + 1 , S[(j + 1) % N]));}
	prep(1 , 0 , N - 1); int pre = 0; mat r; r[0][1] = 1; sval[K] = 0; if(!K){puts("0"); return 0;}
	for(auto t : sval){
		r = r * qry(pre + 2 , t.first); pre = t.first; if(pre == K) break;
		mat T; T[1][0] = 1; T[1][1] = t.second; T[0][1] = sval.find(t.first - 1) == sval.end() ? S[(t.first - 1) % N] : sval[t.first - 1];
		r = r * T;
	}
	cout << r[0][1] << endl; return 0;
}