#include<bits/stdc++.h>
using namespace std;

int A[100003] , cnt[100003] , num[100003] , T , N; deque < int > q;

int main(){
	ios::sync_with_stdio(0);
	for(cin >> T ; T ; --T){
		cin >> N;
		for(int i = 1 ; i <= N ; ++i){
			cin >> A[i]; int cur = i + 1; num[i] = 0;
			while(cur != 1 && A[i] % cur == 0) --cur;
			cnt[i] = cur;
		}
		for(int i = 1 ; i <= 50 ; ++i) for(int j = 1 ; j <= N ; ++j) num[j] = num[j - 1] + (cnt[j] >= j + 1 - num[j - 1]);
		cout << (num[N] == N ? "YES" : "NO") << endl;
	}
	return 0;
}