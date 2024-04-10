#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long int ll;

const int N = 1005;
const int MOD = 1000000007;

int n, k, newton[N][N];

void init_newton () {
    for (int i = 0; i < N; i++) {
        newton[i][0] = 1;
        newton[0][i] = 1;
    }

    for (int i = 1; i < N; i++) {
        int x = 1, y = i;
        while (y >= 1) {
            newton[x][y] = (ll)((ll)(newton[x-1][y]) + (ll)(newton[x][y-1])) % MOD;
            x++;
            y--;
        }
    }

    /*
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%3d ", newton[i][j]);
        }
        printf("\n");
    }
    */
}

int main () {
    init_newton();

	int ttt;
	scanf("%d", &ttt);
	while (ttt--) {
        vector<int> t;
		scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++) {
            int a;
            scanf("%d", &a);

            t.pb(a);
        }

        sort(t.begin(), t.end(), greater<int>());

        int g = t[k-1];
        int ile_wybranych = 0, ile_wszystkich = 0;
        for (int i = k-1; i >= 0; i--)
            if (t[i] == g) ile_wybranych++;

        for (int i = 0; i < n; i++)
            if (t[i] == g) ile_wszystkich++;

        //ile_wybranych = 2, ile_wszystkich = 5;
        int x = ile_wybranych, y = ile_wszystkich - ile_wybranych;

		printf("%d\n", newton[x][y]);
		
	}
	return 0;
}