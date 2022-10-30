#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;

inline int read(){
	int a = 0;
	bool f = 0;
	char c = getchar();
	while(c != EOF && !isdigit(c)){
		if(c == '-')
			f = 1;
		c = getchar();
	}
	while(c != EOF && isdigit(c)){
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar();
	}
	return f ? -a : a;
}

const int MAXN = 100007;
struct query{
	int l , r , ind;
}que[MAXN];
int num[MAXN] , times[1400007] , N , M , K , T;
long long cur , ans[MAXN];

bool cmp(query a , query b){
	return a.l / T == b.l / T ? a.r < b.r : a.l < b.l;
}

inline void add(int x){
	cur += times[x ^ K];
	++times[x];
}

inline void del(int x){
	--times[x];
	cur -= times[x ^ K];
}

int main(){
	N = read();
	M = read();
	K = read();
	T = sqrt(N);
	for(int i = 1 ; i <= N ; ++i)
		num[i] = read() ^ num[i - 1];
	for(int i = 1 ; i <= M ; ++i){
		que[i].l = read();
		que[i].r = read();
		que[i].ind = i;
	}
	sort(que + 1 , que + M + 1 , cmp);
	int L = 1 , R = 0;
	for(int i = 1 ; i <= M ; ++i){
		while(R < que[i].r)
			add(num[++R]);
		while(R > que[i].r)
			del(num[R--]);
		while(L > que[i].l)
			add(num[--L]);
		while(L < que[i].l)
			del(num[L++]);
		add(num[L - 1]);
		ans[que[i].ind] = cur;
		del(num[L - 1]);
	}
	for(int i = 1 ; i <= M ; ++i)
		cout << ans[i] << '\n';
	return 0;
}