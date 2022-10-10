#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vi a(1 << k);
	for(int i = 0; i < n; i ++){
		int s = 0;
		for(int j = 1; j < 1 << k; j <<= 1){
			int x;
			cin >> x;
			s += x * j;
		}
		a[s] ++;
	}
	if(a[0]){
		cout << "YES";
		return 0;
	}
	for(int i = 1; i < 1 << k; i ++){
		for(int j = i + 1; j < 1 << k; j ++){
			if(!(i & j) && a[i] && a[j]){
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";
	return 0;
}