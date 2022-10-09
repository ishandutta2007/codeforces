#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	int a, b, m;
	cin >> a >> b >> m;
	for (int i=0; i<m; i++) {
		if (i > a) break;
		int r = i * 1'000'000'000ll % m;
		// da li b moze da pobedi?
		if (r == 0)
			continue;
		if (m - r <= b)
			continue;
		printf("1 %09d\n", i);
		return 0;		
	}
	cout << "2\n";
}