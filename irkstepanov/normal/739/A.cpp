#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int inf = 1e9;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("wa");

    int n, m;
    scanf("%d%d", &n, &m);

    int minLen = inf;
    while (m--) {
        int l, r;
        scanf("%d%d", &l, &r);
        minLen = min(minLen, r - l + 1);
    }

    printf("%d\n", minLen);
    for (int i = 0; i < n; ++i) {
        printf("%d ", i % minLen);
    }
    printf("\n");

}