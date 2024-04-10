#include <bits/stdc++.h>
using namespace std;
int n, a, b, m;
int main(){
	cin >> n;
	while(n--){
		cin >> a >> b;
		m = max(m, a + b);
	}
	cout << m;
	return 0;
}