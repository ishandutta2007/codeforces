#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define REP(i , j , k) for(int i = j ; i <= k ; ++i)
const int _ = 2e5 + 7;
ll A[_] , ans = 1e18; int N;
void calc(ll fc){ll sum = 0; for(int i = 1 ; i <= N && sum <= ans ; ++i) sum += A[i] < fc ? fc - A[i] : min(fc - A[i] % fc , A[i] % fc); ans = min(ans , sum);}
void check(ll p){if(p > 1){for(ll i = 2 ; i * i <= p ; ++i) if(!(p % i)){calc(i); while(!(p % i)) p /= i;} if(p != 1) calc(p);}}

int main(){
	ios::sync_with_stdio(0); cin >> N; REP(i , 1 , N) cin >> A[i];
	mt19937 rnd(time(0)); shuffle(A + 1 , A + N + 1 , rnd);
	REP(i , 1 , 42){int t = i; check(A[t] - 1); check(A[t]); check(A[t] + 1);}
	cout << ans; return 0;
}