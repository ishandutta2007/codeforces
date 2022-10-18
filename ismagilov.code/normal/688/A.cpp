#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fs first
#define sc second
using namespace std;

bool u[1000];

int main() {
	ios_base::sync_with_stdio(0);
	int n, d;
	cin >> n >> d;
	string a;
	for (int i = 0; i < d; i++){
		cin >> a;
		for (int j = 0; j < n; j++){
			if (a[j] == '0'){
				u[i] = 1;
			}
		}
	}
	int ans = 0;
	int i = 0;
	while(i < d){
		int tek = 0;
		while(!(i > d) && u[i]){
			tek++;
			i++;
		}
		if (tek > ans){
			ans = tek;
		}
		i++;
	}
	cout << ans;
}