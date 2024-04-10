#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, m, r;
int arr[1010];
int brr[1010];
int main() {
    scanf("%d%d%d", &n, &m, &r);

    for (int i=0; i<n; i++) scanf("%d", &arr[i]);
    for (int i=0; i<m; i++) scanf("%d", &brr[i]);

    sort(arr, arr+n);
    sort(brr, brr+m);

    if (arr[0] < brr[m-1]) {
    int cnt = 0;
    for (int i=0; i<n; i++) {
        cnt += r/arr[i];
        r%=arr[i];
    }

    r += cnt*brr[m-1];

    printf("%d", r);
    }
    else {
        printf("%d", r);
    }
}