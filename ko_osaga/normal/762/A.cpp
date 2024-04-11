#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<lint, lint> pi;
const int mod = 1e9 + 7;

lint n, k;
vector<lint> v, rv;
int main(){
	cin >> n >> k;
	for(int i=1;1ll* i*i<=n; i++){
		if(n % i == 0){
			v.push_back(i);
			rv.push_back(n/i);
		}
	}
	if(v.back() == rv.back()) rv.pop_back();
	while(!rv.empty()){
		v.push_back(rv.back());
		rv.pop_back();
	}
	if(v.size() < k) puts("-1");
	else cout << v[k-1];
}