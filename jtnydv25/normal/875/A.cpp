#include <bits/stdc++.h>
using namespace std;

int f(int n){
	int ret = n;
	for(; n; n /= 10){
		ret += n % 10;
	}
	return ret;
}
vector<int> vec;
int main(){
	int n; cin >> n;

	for(int i = n; i >= 1 && i >= n - 100000; i--)
		if(f(i) == n){
			vec.push_back(i);
		}
	sort(vec.begin(), vec.end());
	printf("%d\n", (int)vec.size());
	for(int v : vec) printf("%d\n", v);
}