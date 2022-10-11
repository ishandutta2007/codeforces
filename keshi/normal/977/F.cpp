#include <bits/stdc++.h>
using namespace std;
int n, a[200100], ans, c, b;
map<int, int> m;
int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		b = a[i];
		m[b] = m[b - 1] + 1;
		if(m[b] > m[ans]){
			ans = b;
		}
	}
	cout << m[ans] << endl;
	c = ans - m[ans] + 1;
	for(int i = 0; i < n; i++){
		if(a[i] == c){
			cout << i + 1 << ' ';
			c++;
		}
	}
	return 0;
}