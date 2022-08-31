#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int st = -1e9, ed = 1e9;
int n;
int c[200005], d[200005];

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		scanf("%d %d",&c[i],&d[i]);
	}
	int pl = 0;
	for(int i=n-1; i>=0; i--){
		pl -= c[i];
		if(d[i] == 1){
			st = max(st, 1900 - pl);
		}
		else{
			ed = min(ed, 1899 - pl);
		}
	}
	if(ed > 1e8){
		cout << "Infinity";
		return 0;
	}
	if(st > ed){
		cout << "Impossible";
		return 0;
	}
	cout << ed;
}