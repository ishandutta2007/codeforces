#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int arr[101];
int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    ll temp;
    for (int i=0; i<n; i++) {
        scanf("%lld", &temp);
        arr[temp%k]++;
    }

    int cnt = 2*(arr[0]/2);

    for (int i=1; i<(k+1)/2; i++) {
        cnt += 2*min(arr[i], arr[k-i]);
    }

    if (k%2==0) {
        cnt += 2*(arr[k/2]/2);
    }

    printf("%d\n", cnt);
}