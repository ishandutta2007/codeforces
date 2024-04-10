#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll arr[202020];
ll cnt[202020];
int main() {
    int n;
    scanf("%d", &n);

    for (int i=0; i<n; i++)
    {
        scanf("%lld", &arr[i]);
    }

    cnt[n-1] = arr[n-1];
    for (int i=n-1; i>0; i--) {
        if (cnt[i] == 0)
            cnt[i-1] = 0;
        else
            cnt[i-1] = min(cnt[i]-1, arr[i-1]);
    }

    ll sum = 0;
    for (int i=0; i<n; i++) {
        sum += cnt[i];
    }

    printf("%lld", sum);
}