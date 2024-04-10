#include "bits/stdc++.h"
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	long long n;
	cin >> n;
	vector<long long> arr(n), next(n), prev(n);
	deque<long long> q;
	next.assign(n, -1);
	prev.assign(n, -1);

	for(long long &i : arr) cin >> i;
	vector<long long> vec = arr;

	for(long long i = 0; i < n; ++i)
		for(long long j = 0; j < n; ++j) {
			if(arr[j] * 3 == vec[i]){
				next[i] = j;
				prev[j] = i;
				arr[j] = -1;
				break;
			}
			if(vec[i] * 2 == arr[j]){
				next[i] = j;
				prev[j] = i;
				arr[j] = -1;
				break;
			}
		}

	long long cur = 0;
	while(cur != -1) q.push_back(cur), cur = next[cur];
	cur = prev[0];
	while(cur != -1) q.push_front(cur), cur = prev[cur];
	while(!q.empty()) cout << vec[q.front()] << ' ', q.pop_front();
}