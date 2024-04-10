#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, x, cnt;
vector<int> arr;
bool chk[303030];
int main() {
    scanf("%d %d", &n, &x);

    for (int i=1; i<(1<<n); i++) {
        if (chk[i] || i==x) continue;
        chk[i] = chk[i^x] = true;
        arr.push_back(i);
    }
    arr.push_back(0);

    printf("%d\n", arr.size()-1);
    for (int i=0; i<arr.size()-1; i++) {
        printf("%d ", arr[i]^arr[i+1]);
    }
}