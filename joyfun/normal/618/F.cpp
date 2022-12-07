#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 1000005;

int n;
ll a[N], b[N];
pair<int, int> p[N];
int vis[N];
int flag;

void print(pair<int, int> a, pair<int, int> b) {
    int al = a.first + 1, ar = b.first;
    int bl = a.second + 1, br = b.second;
    if (flag) {
        swap(al, bl);
        swap(ar, br);
    }
    printf("%d\n", ar - al + 1);
    for (int i = al; i <= ar; i++) printf("%d ", i); printf("\n");
    printf("%d\n", br - bl + 1);
    for (int i = bl; i <= br; i++) printf("%d ", i); printf("\n");
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &b[i]);
        b[i] += b[i - 1];
    }
    if (a[n] > b[n]) {
        swap(a, b);
        flag = 1;
    }
    int j = 1;
    vis[0] = 1;
    p[0] = make_pair(0, 0);
    for (int i = 1; i <= n; i++) {
        while (b[j] < a[i]) j++;
        long long d = b[j] - a[i];
        if (vis[d]) {
            print(p[d], make_pair(i, j));
            break;
        }
        vis[d] = 1;
        p[d] = make_pair(i, j);
    }
    return 0;
}