#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, ans[101010];
vector<int>p;
bool sieve[101010] = {true, true};
int main() {
    scanf("%d", &n);

    for (int i=2; i<=n; i++) {
        if (!sieve[i]) {
            for (int j=2; i*j<=n; j++) {
                sieve[i*j] = true;
            }
            p.push_back(i);
        }
    }

    for (int i=2; i<=n; i++) {
        for (int j=0; j<p.size(); j++) {
            if (i%p[j] == 0) {
                printf("%d ", j+1);
                break;
            }
        }
    }
}