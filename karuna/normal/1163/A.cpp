#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, m;
int main() {
    scanf("%d %d", &n, &m);

    int k=n/2;
    if (m==0) printf("1");
    else if (m<=k) printf("%d", m);
    else printf("%d", n-m);
}