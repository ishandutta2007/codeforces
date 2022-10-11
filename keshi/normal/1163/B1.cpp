#include <bits/stdc++.h>
using namespace std;

int cnt[10];
int n, ans, a;

bool check(){
	bool f;
	int u;
	for (int i=0; i<10; i++){
		if (cnt[i]){
			cnt[i]--;
			f = 1;
			u = 0;
			for (int j = 0; j < 10; j++){
				if (cnt[j]){
					u = cnt[j];
					break;
				}
			}
			for (int j = 0; j < 10; j++){
				if (cnt[j] && cnt[j]!=u){
					f = 0;
					break;
				}
			}
			cnt[i]++;
			if (f){
				return 1;
			}
		}
	}
	return 0;
}



int main(){
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> a;
		cnt[a - 1]++;
		if (check()){
			ans = i + 1;
		}
	}
	cout << ans;
}