#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, k, p1, p2, cnt;
vector<int> v;
int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &k);
        if (k%2) ++cnt;
        v.push_back(k);
    }

    if (cnt==n || cnt==0) {
        for (int i=0; i<n; i++) {
            printf("%d ", v[i]);
        }
    }
    else {
        sort(v.begin(), v.end());
        for (int i=0; i<n; i++) {
            printf("%d ", v[i]);
        }
    }
}