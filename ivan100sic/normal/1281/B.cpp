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

	int t;
	cin >> t;
	while (t--) {
		string a, b;
		cin >> a >> b;
		// prvo slovo za koje postoji manje slovo desno od njega
		char mins = 'Z' + 1;
		int j = -1;
		for (int i = a.size()-1; i>=0; i--) {
			if (a[i] > mins)
				j = i;
			mins = min(mins, a[i]);
		}
		if (j != -1) {
			int k = j+1;
			for (int l=j+1; l<(int)a.size(); l++)
				if (a[l] <= a[k])
					k = l;
			swap(a[j], a[k]);
		}
		if (a < b) {
			cout << a << '\n';
		} else {
			cout << "---\n";
		}
	}
}