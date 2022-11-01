#include<bits/stdc++.h>
using namespace std;

int D , M , N , G[60] , B[30003] , pos; unsigned long long pw[64] , L , R;
struct data{
	bitset < 30003 > pre , suf; long long cnt , len;
	void create(int val){
		len = 1; cnt = 0;
		if(N == 1) cnt = val <= B[0];
		else{for(int i = 0 ; i < N ; ++i) pre[i] = B[i] >= val; suf = pre;}
	}
	friend data operator +(data &p , data q){
		data x; x.len = p.len + q.len; int d1 = max(0ll , 30003 - q.len) , d2 = max(0ll , N - p.len);
		x.suf = (q.suf << d1 >> d1) | ((q.suf >> q.len & p.suf) << q.len);
		x.pre = (p.pre >> d2 << d2) | ((p.pre << p.len & q.pre) >> p.len);
		d1 = max(0ll , 30003 - p.len); d2 = max(0ll , N - q.len);
		x.cnt = p.cnt + q.cnt + ((p.suf << d1 >> d1) << 1 & (q.pre >> d2 << d2)).count();
		return x;
	}
}now[64][60];

void init(){
	pw[0] = 1; for(pos = 1 ; pw[pos - 1] < 1e18 ; ++pos) pw[pos] = pw[pos - 1] * D;
	for(int i = 0 ; i < M ; ++i) now[0][i].create(i);
	for(int i = 1 ; i < pos ; ++i)
		for(int j = 0 ; j < M ; ++j){
			now[i][j] = now[i - 1][j];
			for(int k = 1 ; k < D ; ++k)
				now[i][j] = now[i][j] + now[i - 1][(j + G[k]) % M];
		}
}

data solve(int bit , long long val , int delt){
	if(val < pw[bit]) return solve(bit - 1 , val , delt);
	data cur = now[bit][delt]; val -= pw[bit];
	for(int i = 1 ; val && i < D ; ++i)
		if(val < pw[bit]){cur = cur + solve(bit - 1 , val , (delt + G[i]) % M); val = 0;}
		else{cur = cur + now[bit][(delt + G[i]) % M]; val -= pw[bit];}
	return cur;
}

int main(){
	cin >> D >> M; for(int i = 0 ; i < D ; ++i) cin >> G[i];
	cin >> N; for(int i = 0 ; i < N ; ++i) cin >> B[i];
	cin >> L >> R; init(); 
	cout << solve(pos - 1 , R , 0).cnt - (L == 1 ? 0 : solve(pos - 1 , L + N - 2 , 0).cnt) << endl;
	return 0;
}