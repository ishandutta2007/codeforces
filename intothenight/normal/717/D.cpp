#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(15);
	int n, x;
	cin >> n >> x;
	const int MAX = 2 << 7;
	vector<double> p(MAX);
	for(int i = 0; i <= x; i ++){
		cin >> p[i];
	}
	auto product = [&](vector<double> &A, vector<double> &B){
		vector<double> res(MAX);
		for(int i = 0; i < MAX; i ++){
			for(int j = 0; j < MAX; j ++){
				res[i ^ j] += A[i] * B[j];
			}
		}
		return res;
	};
	vector<double> res(MAX);
	res[0] = 1;
	while(n){
		if(n & 1){
			res = product(res, p);
		}
		p = product(p, p);
		n >>= 1;
	}
	cout << 1 - res[0];
	return 0;
}