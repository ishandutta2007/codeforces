#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int b, g, n;
int main() {
	cin >> b >> g >> n;
	cout << min(b, n) + min(g, n) - n+1;
}