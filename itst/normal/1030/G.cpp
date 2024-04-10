#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int p[200003] , N , lst[2000003]; bool nprm[2000003] , fl[2000003];
map < int , pair < int , int > > mx;

void init(){
	for(int i = 2 ; i <= 2e6 ; ++i)
		if(!nprm[i]){
			lst[i] = i;
			for(int j = i ; 1ll * j * i <= 2e6 ; ++j){
				nprm[i * j] = 1; if(!lst[i * j]) lst[i * j] = i;
			}
		}
}

void add(int p){
	int pre = 0 , cnt = 0;
	while(p != 1){
		int t = lst[p]; p /= t;
		if(pre != t){
			if(mx[pre].first < cnt) mx[pre].second = 0;
			if(mx[pre].first <= cnt){mx[pre].first= cnt; ++mx[pre].second;}
			cnt = 0;
		}
		pre = t; ++cnt;
	}
	if(mx[pre].first < cnt) mx[pre].second = 0;
	if(mx[pre].first <= cnt){mx[pre].first= cnt; ++mx[pre].second;}
}

bool check(int p){
	int pre = 0 , cnt = 0;
	while(p != 1){
		int t = lst[p]; p /= t;
		if(pre != t){
			if(pre && mx[pre].first == cnt && mx[pre].second == 1) return 0;
			cnt = 0;
		}
		pre = t; ++cnt;
	}
	if(pre && mx[pre].first == cnt && mx[pre].second == 1) return 0;
	return 1;
}

int main(){
	ios::sync_with_stdio(0); cin >> N; init();
	for(int i = 1 ; i <= N ; ++i) cin >> p[i];
	sort(p + 1 , p + N + 1 , [&](int p , int q){return p > q;}); int pos = 1 , tms = 1; bool flg = 0;
	while(pos <= N){
		int p1 = pos; while(p1 <= N && p[p1] == p[pos]) ++p1;
		add(p[pos]); pos = p1;
	}
	pos = 1;
	while(pos <= N){
		int p1 = pos; while(p1 <= N && p[p1] == p[pos]) ++p1;
		if(p1 - pos + check(p[pos]) >= 2){
			if(p1 - pos == 1){fl[p[pos]] = 1; if(mx[p[pos]].first == 1) --mx[p[pos]].second;}
			add(p[pos] - 1);
		}
		pos = p1;
	}
	pos = 1;
	while(pos <= N){
		int p1 = pos; while(p1 <= N && p[p1] == p[pos]) ++p1;
		if(p1 - pos + (p1 - pos == 1 ? fl[p[pos]] : check(p[pos])) + check(p[pos] - 1) >= 3) flg = 1;
		pos = p1;
	}
	for(auto t : mx) while(t.second.first--) tms = 1ll * tms * t.first % MOD;
	cout << (tms + flg) % MOD;
	return 0;
}