#include<bits/stdc++.h>
//this code is written by Itst
using namespace std;

int read(){
	int a = 0; char c = getchar();
	while(!isdigit(c)) c = getchar();
	while(isdigit(c)){
		a = a * 10 + c - 48; c = getchar();
	}
	return a;
}

const int _ = 2e5 + 7 , M = 1e9 + 7;
int l[_] , r[_] , N;

int poww(long long a , int b){
	int times = 1;
	while(b){
		if(b & 1) times = times * a % M;
		a = a * a % M; b >>= 1;
	}
	return times;
}

#define sz(a , b) ((a) - (b) + 1ll)
int P[_] , pre[_] , suf[_];

int main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	N = read(); long long all = 1; P[1] = 1;
	for(int i = 1 ; i <= N ; ++i) l[i] = read();
	for(int i = 1 ; i <= N ; ++i) r[i] = read();
	for(int i = 2 ; i <= N ; ++i){
		P[i] = M + 1 - poww(sz(r[i] , l[i]) * sz(r[i - 1] , l[i - 1]) % M , M - 2) * max(sz(min(r[i] , r[i - 1]) , max(l[i] , l[i - 1])) , 0ll) % M;
		all = (all + P[i]) % M;
	}
	for(int i = 1 ; i <= N ; ++i) pre[i] = (pre[i - 1] + P[i]) % M;
	for(int i = N ; i ; --i) suf[i] = (suf[i + 1] + P[i]) % M;
	for(int i = 2 ; i < N ; ++i){
#define PII pair < int , int >
#define st first
#define nd second
		int num = sz(r[i - 1] , l[i - 1]) * sz(r[i] , l[i]) % M * sz(r[i + 1] , l[i + 1]) % M;
		vector < PII > pnt; bool flg[3] = {0 , 1 , 1}; int size[3] = {0 , (int)sz(r[i - 1] , l[i - 1]) - 1 , (int)sz(r[i + 1] , l[i + 1]) - 1};
		for(int j = i - 1 ; j <= i + 1 ; j += 2)
			if(l[j] <= r[i] && r[j] >= l[i]){
				if(l[j] <= l[i]) flg[(j - i + 3) >> 1] = 0;
				else pnt.push_back(PII(l[j] , (j - i + 3) >> 1));
				if(r[j] + 1 <= r[i]) pnt.push_back(PII(r[j] + 1 , (j - i + 3) >> 1));
			}
		pnt.push_back(PII(l[i] , 0)); pnt.push_back(PII(r[i] + 1 , 0));
		sort(pnt.begin() , pnt.end()); int pos = 1; long long sum = 0;
		while(pos < (int)pnt.size()){
			sum = (sum + 1ll * (pnt[pos].first - pnt[pos - 1].first) * (size[1] + flg[1]) % M * (size[2] + flg[2])) % M;
			flg[pnt[pos++].second] ^= 1;
		}
		all = (all + 2 * sum * poww(num , M - 2)) % M;
	}
	for(int i = 1 ; i <= N ; ++i)
		all = (all + 1ll * P[i] * (pre[max(i - 2 , 0)] + suf[i + 2])) % M;
	cout << (all + 2 * P[2]) % M;
	return 0;
}