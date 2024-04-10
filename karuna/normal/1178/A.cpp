#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, num, p, sum;
pii arr[101];
int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i].va;
        sum += arr[i].va;
        arr[i].vb = i+1;
    }

    sort(arr+1, arr+n);

    p=1, num=arr[0].va;

    while (2*arr[p].va<=arr[0].va && p<n) {
        if (2*num>sum) break;
        num += arr[p].va;
        ++p;
    }

    if (2*num<=sum) cout << '0';
    else {
        cout << p << '\n';
        for (int i=0; i<p; i++) {
            cout << arr[i].vb << ' ';
        }
    }
}