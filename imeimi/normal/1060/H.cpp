#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int nCr[30][30];
int arr[20][20];
int rev[20][20];

int pw(int x, int p, int m) {
    int r = 1;
    while (p) {
        if (p & 1) r = (llong)r * x % m;
        x = (llong)x * x % m;
        p >>= 1;
    }
    return r;
}

int d, p;
void getPow(int st, int ed) {
    printf("^ 4 10\n");
    for (int i = 11; i <= 10 + d; ++i) {
        printf("+ %d %d %d\n", i - 1, st, i);
    }
    for (int i = 11; i <= 10 + d; ++i) {
        printf("^ %d %d\n", i, i);
    }
    printf("^ 4 %d\n", ed);
    for (int i = 0; i <= d; ++i) {
        int x = rev[2][i];
        while (x) {
            if (x & 1) {
                printf("+ %d %d %d\n", 10 + i, ed, ed);
            }
            printf("+ %d %d %d\n", 10 + i, 10 + i, 10 + i);
            
            x >>= 1;
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> d >> p;
	nCr[0][0] = 1;
	for (int i = 1; i < 30; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j > 0) nCr[i][j] += nCr[i - 1][j - 1];
            if (j < i) nCr[i][j] += nCr[i - 1][j];
            nCr[i][j] %= p;
        }
	}
	for (int i = 0; i <= d; ++i) {
        rev[i][i] = 1;
        for (int j = 0; j <= d; ++j) {
            arr[i][j] = (llong)nCr[d][j] * pw(i, j, p) % p;
        }
	}
	
	for (int i = 0; i <= d; ++i) {
        int x = pw(arr[i][i], p - 2, p);
        for (int j = 0; j <= d; ++j) {
            arr[i][j] = (llong)arr[i][j] * x % p;
            rev[i][j] = (llong)rev[i][j] * x % p;
        }
        for (int j = i + 1; j <= d; ++j) {
            int y = arr[j][i];
            for (int k = 0; k <= d; ++k) {
                rev[j][k] += p - (llong)y * rev[i][k] % p;
                rev[j][k] %= p;
                arr[j][k] += p - (llong)y * arr[i][k] % p;
                arr[j][k] %= p;
            }
        }
	}
	
	for (int i = d; 0 <= i; --i) {
        for (int j = i - 1; 0 <= j; --j) {
            int y = arr[j][i];
            for (int k = 0; k <= d; ++k) {
                rev[j][k] += p - (llong)y * rev[i][k] % p;
                rev[j][k] %= p;
                arr[j][k] += p - (llong)y * arr[i][k] % p;
                arr[j][k] %= p;
            }
        }
	}
	
	rev[2][0] = (rev[2][0] + p - 1) % p;
	
	printf("+ 1 2 3\n");
	getPow(1, 1001);
	getPow(2, 1002);
	getPow(3, 1003);
	int x = p - 1;
	while (x) {
        if (x & 1) {
            printf("+ 1001 1003 1003\n");
            printf("+ 1002 1003 1003\n");
            printf("+ 4 1004 1004\n");
        }
        printf("+ 1001 1001 1001\n");
        printf("+ 1002 1002 1002\n");
        printf("+ 4 4 4\n");
        
        x >>= 1;
	}
	
	x = (p + 1) / 2;
	while (x) {
        if (x & 1) {
            printf("+ 1003 1004 1004\n");
        }
        printf("+ 1003 1003 1003\n");
        
        x >>= 1;
	}
	
	printf("f 1004\n");
	return 0;
}