// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

    int n;
    cin >> n;

    if (n <= 3) {
        cout << 0 << '\n' << flush;
        return 0;
    }

    vector<bool> a(n), b(n);

		int x1 = -1, x2 = -1, c1 = -1, c2 = -1, o = -1;

		for (int x1i=1; x1i<n; x1i++) {
			for (int c1i=1; c1i<n; c1i++) {
				if ((x1i + 1) * c1i > n)
					break;

				for (int x2i=1; x2i<=x1i; x2i++) {
					for (int c2i=0; c2i<n; c2i++) {
						if ((x1i + 1) * c1i + (x2i + 1) * c2i > n)
							break;

						int v = x1i * (c1i - 1) + x2i * c2i;

						if (v > o) {
							o = v;
							x1 = x1i;
							x2 = x2i;
							c1 = c1i;
							c2 = c2i;
						}
					}
				}
			}
		}

		cerr << x1 << ' ' << c1 << ' ' << x2 << ' ' << c2 << ": " << o << '\n';

    {
        int j = 0;

				for (int i=0; i<c1; i++) {
					for (int i=0; i<x1; i++)
						a[j++] = 1;
					j++;
				}

				for (int i=0; i<c2; i++) {
					for (int i=0; i<x2; i++)
						a[j++] = 1;
					j++;
				}
    }

    while (o != count(begin(b), end(b), 1)) {
        vector<int> diff;
        for (int i=0; i<n; i++) {
            if (a[i] != b[i]) {
                diff.push_back(i);
            }
        }

        cout << diff.size();
        for (int x : diff) {
            b[x] = 1;
            cout << ' ' << x+1;
        }
        cout << '\n' << flush;

        int s;
        cin >> s;
        s--;
        for (size_t i=0; i<diff.size(); i++) {
            b[(i+s) % n] = 0;
        }
    }

    cout << "0\n" << flush;
}