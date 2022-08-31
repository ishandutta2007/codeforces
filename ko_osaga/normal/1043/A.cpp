#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 100005;

int n, a[MAXN];

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	int ptr = *max_element(a, a + n);
	ptr = max(ptr, (2 * accumulate(a, a + n, 0) + n) / n); 
	cout << ptr << endl;
}