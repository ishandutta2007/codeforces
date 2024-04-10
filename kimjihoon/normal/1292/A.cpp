#include <iostream>
#include <algorithm>
using namespace std;	

bool d[100009][3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q; cin >> n >> q;
	int c = 0;
	for (int i = 0; i < q; i++) {
		int a, b; cin >> a >> b;
		if (d[b][a]) {
			for (int j = -1; j <= 1; j++)
				if (d[b + j][3 - a]) 
					c--;
			d[b][a] = false;
		}
		else {
			d[b][a] = true;
			for (int j = -1; j <= 1; j++)
				if (d[b + j][3 - a])
					c++;
		}
		if (c == 0) cout << "Yes" << '\n';
		else cout << "No" << '\n';
	}
	return 0;
}