#include<bits/stdc++.h>
using namespace std;

int N , A[300003] , cnt[300003] , T; bool ans[300003];

int main(){
	ios::sync_with_stdio(0);
	for(cin >> T ; T ; --T){
		cin >> N; for(int i = 1 ; i <= N ; ++i) cnt[i] = ans[i] = 0;
		deque < int > q; for(int i = 1 ; i <= N ; ++i){cin >> A[i]; ++cnt[A[i]]; q.push_back(A[i]);}
		ans[1] = 1; for(int i = 1 ; i <= N ; ++i) ans[1] &= cnt[i] == 1;
		for(int i = 1 ; i <= N ; ++i){
			if(!cnt[i]) break;
			ans[N - i + 1] = 1; if(cnt[i] != 1 || (q.front() != i && q.back() != i)) break;
			if(q.front() == i) q.pop_front(); else q.pop_back();
		}
		for(int i = 1 ; i <= N ; ++i) putchar(ans[i] + '0');
		puts("");
	}
	return 0;
}