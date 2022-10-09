#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;

	int b = n/3;
	int a = (n-b)/2;
	int c = n-a-b;

	for (int i=0; i<a; i++)
		cout << "1 " << 2*i << '\n';
	for (int i=0; i<b; i++)
		cout << "2 " << 2*i+1 << '\n';
	for (int i=0; i<c; i++)
		cout << "3 " << 2*i << '\n';
}