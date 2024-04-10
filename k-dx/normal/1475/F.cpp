#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long int ll;

const int N = 1005;

int n, a[N][N], b[N][N];

void hor (int x) {
    for (int i = 0; i < n; i++) {
        a[i][x] = !a[i][x];
    }
}

void vert (int x) {
    for (int i = 0; i < n; i++) {
        a[x][i] = !a[x][i];
    }
}

int main () {
	int ttt;
    cin >> ttt;
	while (ttt--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < n; j++) {
                char temp = s[j];

                a[i][j] = temp - '0';
            }
        }

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < n; j++) {
                char temp = s[j];

                b[i][j] = temp - '0';
            }
        }

        for (int i = 0; i < n; i++) {
            if (a[i][0] != b[i][0])
                vert(i);
        }

        bool ok = true;
        for (int i = 1; i < n; i++) {
            int diffs = 0;
            for (int j = 0; j < n; j++) {
                if (a[j][i] != b[j][i]) {
                    diffs++;
                }
            }

            if (diffs != 0 and diffs != n)
                ok = false;
        }

        if (ok)
            cout << "YES\n";
        else
            cout << "NO\n";
		
	}
	return 0;
}