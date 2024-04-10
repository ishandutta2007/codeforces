#include<bits/stdc++.h>
using namespace std;

const int _ = 1e5 + 7 , __ = 1e7 + 7;
int N , K , A[_] , cnt[__]; vector < int > pot[_] , ans;

void add(int x , int flg){
	for(int i = 1 ; i < 1 << pot[x].size() ; ++i){
		int tms = 1; for(int j = 0 ; j < pot[x].size() ; ++j) if(i >> j & 1) tms *= pot[x][j];
		cnt[tms] += flg;
	}
}

int calc(int x){
	int sum = 0;
	for(int i = 1 ; i < 1 << pot[x].size() ; ++i){
		int tms = 1; for(int j = 0 ; j < pot[x].size() ; ++j) if(i >> j & 1) tms *= pot[x][j];
		sum += (__builtin_popcount(i) & 1 ? 1 : -1) * cnt[tms];
	}
	return sum;
}

int main(){
	cin >> N >> K;
	for(int i = 1 ; i <= N ; ++i){
		cin >> A[i]; int t = A[i];
		for(int j = 2 ; j * j <= t ; ++j)
			if(t % j == 0){pot[i].push_back(j); while(t % j == 0) t /= j;}
		if(t != 1) pot[i].push_back(t);
		add(i , 1);
	}
	int pos = 0; for(int i = 1 ; i <= N ; ++i) if(calc(i) <= N - 2){pos = i; break;}
	if(!pos){
		memset(cnt , 0 , sizeof(cnt));
		for(int i = 1 ; ans.size() < K ; ++i)
			if(calc(i) == ans.size()){add(i , 1); ans.push_back(i);}
		for(auto t : ans) printf("%d " , t);
	}else{
		int x = 0 , y = 0; for(int i = 1 ; !y ; ++i) if(__gcd(A[i] , A[pos]) == 1) (!x ? x : y) = i;
		memset(cnt , 0 , sizeof(cnt)); vector < int > pot , ban;
		for(int i = 1 ; i <= N ; ++i) if(i != pos && i != x && i != y) add(i , 1);
		for(int i = 1 ; ans.size() < K && i <= N ; ++i)
			if(i != pos && i != x && i != y) (calc(i) == N - 3 ? ans : pot).push_back(i);
		if(ans.size() < K){
			ans = {pos , x , y}; memset(cnt , 0 , sizeof(cnt)); int L = 1 , R = pot.size();
			while(L < R){
				int mid = (L + R) >> 1; for(int i = 0 ; i < mid ; ++i) add(pot[i] , 1);
				int cnt = 0; for(int i = 0 ; i < mid ; ++i) cnt += calc(pot[i]) != mid;
				for(int i = 0 ; i < mid ; ++i) add(pot[i] , -1);
				cnt >= K - 3 ? R = mid : L = mid + 1;
			}
			ans.push_back(pot[L - 1]); for(int i = 0 ; i < L ; ++i) add(pot[i] , 1);
			for(int i = 0 ; i + 1 < L ; ++i)
				if(calc(pot[i]) != L){
					ans.push_back(pot[i]); if(__gcd(A[pot[i]] , A[pot[L - 1]]) == 1 && calc(pot[i]) == L - 1) ban.push_back(pot[i]);
				}
			if(ban.size()) ban.pop_back();
			if(ans.size() - ban.size() > K) ban.push_back(x);
			while(ans.size() - ban.size() < K) ban.pop_back();
			sort(ans.begin() , ans.end()); sort(ban.begin() , ban.end()); int pban = 0;
			for(auto t : ans) if(ban.size() != pban && ban[pban] == t) ++pban; else printf("%d " , t);
		}else for(auto t : ans) printf("%d " , t);
	}
	return 0;
}