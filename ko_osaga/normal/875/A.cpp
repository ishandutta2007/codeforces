#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int MAXN = 100005;
const int mod = 1e9 + 7;

int digit(int x){
	return x < 10 ? x : (digit(x / 10) + x % 10);
}

int n;
int main(){
	cin >> n;
	vector<int> v;
	for(int i=n-500; i<=n; i++){
		if(i > 0 && i + digit(i) == n) v.push_back(i);
	}
	cout << v.size() << endl;
	for(auto &i : v) cout << i << endl;
}