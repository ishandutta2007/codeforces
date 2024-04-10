#include<bits/stdc++.h>
using namespace std;

int T , N , A[100003] , L;

int main(){
	ios::sync_with_stdio(0);
	for(cin >> T ; T ; --T){
		cin >> N >> L; for(int i = 1 ; i <= N ; ++i) cin >> A[i];
		A[0] = 0; A[N + 1] = L;
		long double t1 = 0 , t2 = 0 , tt1 = A[1] - A[0] , tt2 = A[N + 1] - A[N];
		int p1 = 1 , p2 = N;
		while(p1 <= p2){
			if(tt1 < tt2){t1 = tt1; ++p1; tt1 += (A[p1] - A[p1 - 1]) * 1.0/ p1;}
			else{t2 = tt2; --p2; tt2 += (A[p2 + 1] - A[p2]) * 1.0 / (N - p2 + 1);}
		}
		cout << fixed << setprecision(10) << max(t1 , t2) + abs((A[p1] - A[p2] - (t1 < t2 ? (t2 - t1) * p1 : (t1 - t2) * (N - p2 + 1))) / (p1 + N - p2 + 1)) << endl;
	}
	return 0;
}