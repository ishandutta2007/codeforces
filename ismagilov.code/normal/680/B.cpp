#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fs first
#define sc second
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int n, a;
	cin >> n >> a;
	bool m[n];
	for (int i = 0; i < n; i++){
		cin >> m[i];
	}
	int kol = 0;
	a--;
	for (int i = 0; i <= min(n - a - 1, a); i++){
		if ((!m[a-i] && m[a+i]) || (m[a-i] && !m[a+i])){
			kol--;	
		}
	}
	for (int i = 0; i < n; i++){
		kol += m[i];	
	}
	cout << kol;
	
}