#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n;
int arr[101010];
int cnt[101010];
int numcnt[101010];
int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    numcnt[0] = n;
    int hi = 0;
    int ans;

    for (int i=0; i<n; i++) {
        numcnt[cnt[arr[i]]]--;
        cnt[arr[i]]++;
        numcnt[cnt[arr[i]]]++;

        hi = max(hi, cnt[arr[i]]);

        if (hi == 1) ans = i+1;
        else if (hi == 2 && numcnt[2] == 1) ans = i+1;
        else if (numcnt[hi] == 1 && numcnt[hi-1]*(hi-1)+hi == i+1) ans = i+1;
        else if (numcnt[1] == 1 && numcnt[hi]*hi+1 == i+1) ans = i+1;
    }
    printf("%d", ans);
}