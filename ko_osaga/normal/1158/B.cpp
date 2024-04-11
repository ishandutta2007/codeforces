#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
using pi = pair<int, int>;
const int MAXN = 500005;
const int mod = 1e9 + 7;

bool hasUnique(vector<string> v){
	sort(v.begin(), v.end());
	for(int i=0; i<v.size(); i++){
		bool uniq = 1;
		if(i && v[i-1] == v[i]) uniq = 0;
		if(i + 1 < v.size() && v[i] == v[i+1]) uniq = 0;
		if(uniq) return 1;
	}
	return 0;
}

int main(){
	int n, k;
	cin >> n >> k;
	int period = (n - k) / 2 + 1;
	for(int i=0; i<n; i++){
		if(i % period == period - 1) putchar('0');
		else putchar('1');

	}
}