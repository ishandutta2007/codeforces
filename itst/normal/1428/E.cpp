#include<bits/stdc++.h>
using namespace std;

#define int long long
int N , K , A[100003] , C[100003] , sum;
int calc(int A , int num){int L = A / num , lft = A % num; return (num - lft) * L * L + lft * (L + 1) * (L + 1);}

signed main(){
	cin >> N >> K; priority_queue < pair < int , int > > q;
	for(int i = 1 ; i <= N ; ++i){
		cin >> A[i]; C[i] = 1; sum += A[i] * A[i]; --K;
		q.push(make_pair(calc(A[i] , 1) - calc(A[i] , 2) , i));
	}
	while(K--){
		sum -= q.top().first; int t = q.top().second; q.pop();
		++C[t]; q.push(make_pair(calc(A[t] , C[t]) - calc(A[t] , C[t] + 1) , t));
	}
	cout << sum; return 0;
}