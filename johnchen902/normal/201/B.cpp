#include <iostream>
#include <limits>

using namespace std;

long long rarity[1000][1000];
long long hori[1000], vert[1000];

void decide(long long *a, int length, long long& min, long long& minId) {
    min = numeric_limits<long long>::max();
    for (int i = 0; i <= length; i++) {
        long long val = 0;
        for (int j = 0; j < length; j++) {
            val += a[j] * ((long long)(i * 4 - j * 4 - 2) * (long long)(i * 4 - j * 4 - 2));
        }
        if (min > val) {
            min = val;
            minId = i;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            cin     >> rarity[i][j];
            hori[i] += rarity[i][j];
            vert[j] += rarity[i][j];
        }
    long long sum1, id1; decide(hori, n, sum1, id1);
    long long sum2, id2; decide(vert, m, sum2, id2);

    cout << (sum1 + sum2) << endl << id1 << " " << id2 << endl;
}