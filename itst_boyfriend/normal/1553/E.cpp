#include<bits/stdc++.h>
using namespace std;

int T , N , M , A[300003] , cnt[300003];

bool check(int id){
	static int trs[300003]; int cnt = 0;
	for(int p = 1 ; p <= N ; ++p){int q = (A[p] - id + N) % N; trs[p] = q ? q : N;}
	for(int i = 1 ; i <= N ; ++i)
		if(trs[i]){int p = i; --cnt; do{int r = trs[p]; trs[p] = 0; p = r; ++cnt;}while(trs[p]);}
	return cnt <= M;
}

int main(){
	for(cin >> T ; T ; --T){
		cin >> N >> M; for(int i = 0 ; i < N ; ++i) cnt[i] = 0;
		for(int i = 1 ; i <= N ; ++i){cin >> A[i]; ++cnt[(A[i] - i + N) % N];}
		vector < int > pot;
		for(int i = 0 ; i < N ; ++i)
			if(cnt[i] >= N - 2 * M && check(i)) pot.push_back(i ? N - i : 0);
		sort(pot.begin() , pot.end()); cout << pot.size() << ' '; for(auto t : pot) cout << t << ' ';
		cout << endl;
	}
	return 0;
}