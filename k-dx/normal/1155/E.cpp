#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

const int N = 15;
const int MOD = 1e6+3;

int n;
vector<int> t[N];

int norm(int a) {
	while(a >= MOD) a -= MOD;
	while(a < 0) a += MOD;
	return a;
}
int mul(int a, int b) {
	return int(a * 1ll * b % MOD);
}
int binPow(int a, int k) {
	int ans = 1;
	while(k > 0) {
		if(k & 1)
			ans = mul(ans, a);
		a = mul(a, a);
		k >>= 1;
	}
	return ans;
}
int inv(int a) {
	return binPow(a, MOD - 2);
}

int pot (ll a, int b) {
    ll w = 1;
    while (b--) {
        w = w * a % MOD;
        //printf("%lld\n", w);
    }
    return w;
}

void gauss () {
    for (int kol = 0; kol < 12; kol++) {
        int nid = -1;
        for (int i = kol; i < 11; i++) {
            if (t[i][kol] != 0) {
                nid = i;
                break;
            }
        }
        if (nid == -1) continue;

        swap(t[kol], t[nid]);

        for (int wie = 0; wie < 11; wie++) {
            if (kol == wie) continue;

            //printf("[%d %d]\n", kol, wie);
            int wsp = mul(t[wie][kol], inv(t[kol][kol]));

            for (int i = 0; i < 12; i++) {
                t[wie][i] = norm(t[wie][i] - mul(wsp, t[kol][i]));
            }
        }
    }
}

void wypisz () {
    printf("-------------------------------------------\n");
    for (int wie = 0; wie < 11; wie++) {
        for (int kol = 0; kol < 12; kol++) {
            printf("%3d ", t[wie][kol]);
        }
        printf("\n");
    }
}

int main () {
    /*
    int a,b;
    scanf("%d %d", &a, &b);
    printf("%d\n", pot(a,b));
    return 0;
    */

    //vector<int> input = {1000002, 0, 1, 3, 8, 15, 24, 35, 48, 63, 80};
    vector<int> input = {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < N; i++) {
        t[i].resize(13);
    }

    for (int i = 0; i < 11; i++) {
        printf("? %d\n", i);
        fflush(stdout);
        scanf("%d", &t[i][11]);

        //t[i][11] = input[i];

        t[i][0] = 1;
        for (int kol = 1; kol < 11; kol++) {
            t[i][kol] = mul(t[i][kol-1], i);
        }
    }

    //wypisz();

    gauss();

    //wypisz();

    vector<int> a(11, 0);
    for (int i = 0; i < a.size(); i++) {
		if (t[i][i] == 0)
			continue;
		a[i] = mul(t[i][a.size()], inv(t[i][i]));
	}

    for (int x = 0; x < MOD; x++) {
        int val = 0;
		for(int i = a.size() - 1; i >= 0; i--)
			val = norm(mul(val, x) + a[i]);

		if(val == 0) {
            printf("! %d\n", x);
			return 0;
		}
    }

    printf("! -1\n");



	return 0;
}