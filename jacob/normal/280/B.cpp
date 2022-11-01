#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i =0 ; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    vector<char> isCurBitSet(n);
    for (int curbit = 30; curbit >= 0; --curbit) {
        isCurBitSet.assign(n, 0);
        for (int i = 0; i < n; ++i) {
            isCurBitSet[i] = (a[i] >> curbit) & 1;
        }
        int cnt = count(isCurBitSet.begin(), isCurBitSet.end(), char(1));
        if (cnt == n || cnt == 0)
            continue;
        int result = 0;
        for (int i = 0; i < n; ++i) {
            if (!isCurBitSet[i]) continue;
            int cmax = -1;
            for (int j = i - 1; j >= 0 && !isCurBitSet[j]; --j) {
                cmax = max(cmax, a[j]);
                result = max(result, cmax ^ a[i]);
            }
            cmax = -1;
            for (int j = i + 1; j < n && !isCurBitSet[j]; ++j) {
                cmax = max(cmax, a[j]);
                result = max(result, cmax ^ a[i]);
            }
        }
        printf("%d\n", result);
        return 0;
    }
    printf("0\n");
}