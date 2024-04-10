#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, m;
ll arr[202020];
int main() {
    scanf("%d", &n);

    int p, q;
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i]) p = i;
        else q = i;
    }

    printf("%d", min(p, q)+1);
}