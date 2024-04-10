#include<bits/stdc++.h>
using namespace std;

const int _ = 2e5 + 7;
#define eps 1e-9
#define ld long double
struct prob{
	int T , A;
	friend bool operator <(prob p , prob q){return 1ll * p.T * q.A < 1ll * q.T * p.A;}
	friend bool operator ==(prob p , prob q){return !(p < q) && !(q < p);}
}now[_]; int srtA[_] , pos[_] , N; ld mx[_] , mn[_]; long long T;

bool check(ld mid){
	long long presum = 0;
	for(int i = 1 , pi = 1 ; i <= N ; i = pi){
		long long all = 0; while(pi <= N && now[i] == now[pi]) all += now[pi++].T;
		for(int j = i ; j < pi ; ++j){
			mn[pos[j]] = now[j].A * (1 - mid * (presum + all) / T);
			mx[pos[j]] = now[j].A * (1 - mid * (presum + now[j].T) / T);
		}
		presum += all;
	}
	ld premn = 1e18;
	for(int i = 1 , pi = 1 ; i <= N ; i = pi){
		while(now[srtA[i]].A == now[srtA[pi]].A) ++pi;
		for(int j = i ; j < pi ; ++j) if(premn + eps < mx[j]) return 0;
		for(int j = i ; j < pi ; ++j) premn = min(premn , mn[j]);
	}
	return 1;
}

int main(){
	cin >> N; for(int i = 1 ; i <= N ; ++i) cin >> now[i].A;
	for(int i = 1 ; i <= N ; ++i){cin >> now[i].T; T += now[i].T;}
	sort(now + 1 , now + N + 1); for(int i = 1 ; i <= N ; ++i) srtA[i] = i;
	sort(srtA + 1 , srtA + N + 1 , [&](int p , int q){return now[p].A > now[q].A;});
	for(int i = 1 ; i <= N ; ++i) pos[srtA[i]] = i;
	
	ld L = 0 , R = 1; while(L + eps < R){ld mid = (L + R) / 2; check(mid) ? L = mid : R = mid;}
	cout << fixed << setprecision(10) << L << endl; return 0;
}