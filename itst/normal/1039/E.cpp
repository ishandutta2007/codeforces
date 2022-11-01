#include<bits/stdc++.h>
#define PII pair < int , int >
#define st first
#define nd second
//This code is written by Itst
using namespace std;

inline int read(){
	int a = 0;
	char c = getchar();
	bool f = 0;
	while(!isdigit(c))
		c = getchar();
	while(isdigit(c)){
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar();
	}
	return f ? -a : a;
}

inline int max(int a , int b){
	return a > b ? a : b;
}

inline int min(int a , int b){
	return a < b ? a : b;
}

const int MAXN = 1e5 + 10;
int N , W , Q , logN , j_small , j_big;
int num[MAXN] , logg2[MAXN] , ST[21][MAXN][2] , pre[MAXN] , nxt[MAXN] , nMax[MAXN] , nMin[MAXN] , cnt[MAXN] , len[MAXN] , ans[MAXN];
bool vis[MAXN];
priority_queue < PII > q , mod;
deque < int > v;

void input(){
	N = read();
	j_small = pow(N , 1.0 / 3);
	j_big = pow(N , 2.0 / 3);
	W = read();
	Q = read();
	for(int i = 1 ; i <= N ; ++i)
		num[i] = ST[0][i][0] = ST[0][i][1] = read();
	for(int i = 1 ; i <= Q ; ++i)
		q.push(PII(read() , i));
}

void init(){
	for(int i = 1 ; 1 << i <= N ; ++i)
		for(int j = 1 ; j + (1 << i) - 1 <= N ; ++j){
			ST[i][j][0] = min(ST[i - 1][j][0] , ST[i - 1][j + (1 << (i - 1))][0]);
			ST[i][j][1] = max(ST[i - 1][j][1] , ST[i - 1][j + (1 << (i - 1))][1]);
		}
	logg2[0] = -1;
	for(int i = 1 ; i <= N ; ++i){
		logg2[i] = logg2[i >> 1] + 1;
		nxt[i] = i + 1;
		pre[i] = min(N + 1 , j_small + i);
		cnt[i] = pre[i] - i;
		nMax[i] = max(num[i] , num[i + 1]);
		nMin[i] = min(num[i] , num[i + 1]);
		if(i != N)
			mod.push(PII(nMin[i] - nMax[i] , i));
	}
	logN = 1;
	while(logN << 1 <= N)
		logN <<= 1;
	logN = logg2[logN];
}

void upd(int p , PII t){
	mod.pop();
	while(nxt[p] <= N && nMax[p] - nMin[p] <= t.st && nxt[p] - p <= j_big){
		++nxt[p];
		if(nxt[p] <= N){
			if(nMax[p] < num[nxt[p]])
				nMax[p] = num[nxt[p]];
			if(nMin[p] > num[nxt[p]])
				nMin[p] = num[nxt[p]];
		}
	}
	if(nxt[p] <= N && nxt[p] - p <= j_small)
		mod.push(PII(nMin[p] - nMax[p] , p));
	pre[p] = p;
	cnt[p] = len[p] = 0;
	v.clear();
	v.push_back(p);
	vis[p] = 1;
	while(pre[p] <= N && nxt[pre[p]] - p <= j_small){
		pre[p] = nxt[pre[p]];
		++cnt[p];
		v.push_back(pre[p]);
	}
	for(int i = p - 1 ; i && i >= p - j_small ; --i)
		if(vis[nxt[i]]){
			while(v.back() - i > j_small)
				v.pop_back();
			pre[i] = v.back();
			cnt[i] = len[nxt[i]] + v.size();
			len[i] = len[nxt[i]] + 1;
			vis[i] = 1;
		}
	memset(vis + max(p - j_small , 1) , 0 , sizeof(bool) * (j_small + 1));
}

void work(){
	while(!q.empty()){
		PII t = q.top();
		q.pop();
		t.st = W - t.st;
		while(!mod.empty() && -mod.top().st <= t.st)
			upd(mod.top().nd , t);
		int p = 1 , all = 0;
		while(p <= N){
			int cur = nxt[p] - p;
			if(cur <= j_small){
				all += cnt[p];
				p = pre[p];
			}
			else{
				++all;
				while(nxt[p] <= N && nMax[p] - nMin[p] <= t.st && cur <= j_big){
					++nxt[p];
					++cur;
					if(nxt[p] <= N){
						if(nMax[p] < num[nxt[p]])
							nMax[p] = num[nxt[p]];
						if(nMin[p] > num[nxt[p]])
							nMin[p] = num[nxt[p]];
					}
				}
				if(cur <= j_big)
					p = nxt[p];
				else{
					int cMax = 0 , cMin = 1e9;
					for(int j = logN ; j >= 0 ; --j)
						if(p + (1 << j) - 1 <= N){
							int m = max(cMax , ST[j][p][1]) , n = min(cMin , ST[j][p][0]);
							if(m - n <= t.st){
								cMax = m;
								cMin = n;
								p += 1 << j;
							}
						}
				}
			}
		}
		ans[t.nd] = all;
	}
}

void output(){
	for(int i = 1 ; i <= Q ; ++i)
		printf("%d\n" , ans[i] - 1);
}

int main(){
	input();
	init();
	work();
	output();
	return 0;
}