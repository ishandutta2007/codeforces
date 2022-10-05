#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll a, b, c;

int main(){
	cin >> a >> b >> c;
	cout << (2 * c + 2 * min(a, b) + !!abs(a - b)) << endl;
}