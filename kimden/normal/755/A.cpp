#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using ull = unsigned long long;





int main() {
    int n;
    cin >> n;
    if(n <= 998){
    cout << n + 2 << endl;
	}
	else {
		cout << n-2 << endl;
	}
    return 0;
}