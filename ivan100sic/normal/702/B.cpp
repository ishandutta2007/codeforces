#include "bits/stdc++.h"
using namespace std;

map<int, int> cnt;
vector<int> a;

long long s;

int main(){
	int n;
	cin >> n;
	while (n--){
		int x;
		cin >> x;
		for (int t=1; t>0; t<<=1){
			s += cnt[t-x];
		}		
		cnt[x]++;
	}
	cout << s;
	return 0;
}