#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int _ = 1e5 + 7;
int N , A[_] , B[_]; ll K;

int main(){
	cin >> N >> K; for(int i = 1 ; i <= N ; ++i) cin >> A[i];
	ll L = -3e18 , R = 1e9;
	while(L < R){
		ll mid = (L + R) >> 1 , sum = 0;
		for(int j = 1 ; j <= N ; ++j){
			int L = 0 , R = A[j];
			while(L < R){int md = (L + R + 1) >> 1; -3ll * md * md + 3ll * md - 1 + A[j] >= mid ? L = md : R = md - 1;}
			sum += L;
		}
		sum >= K ? L = mid + 1 : R = mid;
	}
	ll lstval = L;
	for(int j = 1 ; j <= N ; ++j){
		int L = 0 , R = A[j];
		while(L < R){int md = (L + R + 1) >> 1; -3ll * md * md + 3ll * md - 1 + A[j] >= lstval ? L = md : R = md - 1;}
		K -= L; B[j] = L;
	}

	priority_queue < pair < ll , int > > q;
	for(int i = 1 ; i <= N ; ++i) q.push(make_pair(B[i] == A[i] ? (ll)-5e18 : -3ll * (B[i] + 1) * (B[i] + 1) + 3ll * (B[i] + 1) - 1 + A[i] , i));
	while(K--){
		int i = q.top().second; q.pop(); ++B[i];
		q.push(make_pair(B[i] == A[i] ? (ll)-5e18 : -3ll * (B[i] + 1) * (B[i] + 1) + 3ll * (B[i] + 1) - 1 + A[i] , i));
	}
	
	for(int i = 1 ; i <= N ; ++i) cout << B[i] << ' ';
	return 0;
}