#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define cin fin
#define cout fout

int n, m;
int a[100005], b[100005];
int sol[200005], arr[200005];

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	cin >> m;
	for (int i=1; i<=m; i++)
		cin >> b[i];

	int x = n, y = m;
	int curr = 0;
	while (x || y) {
		bool prvi;
		if (!x)
			prvi = false;
		else if (!y)
			prvi = true;
		else {
			if (a[x] == curr)
				prvi = true;
			else if (b[y] == curr)
				prvi = false;
			else {
				curr ^= 1;
				continue;				
			}
		}

		if (prvi) {
			sol[x+y] = x;
			arr[x+y] = a[x];
			x--;
		} else {
			sol[x+y] = y + n;
			arr[x+y] = b[y];
			y--;
		}
	}

	for (int i=1; i<=n+m; i++)
		cout << sol[i] << ' ';
	cout << '\n';

	vector<int> f;
	for (int i=1; i<=n+m; i++)
		if (arr[i] != arr[i+1])
			f.push_back(i);

	cout << f.size() << '\n';
	for (int x : f)
		cout << x << ' ';
	cout << '\n';
}