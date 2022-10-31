// Hydro submission #62cd072de4874952a0849921@1657603885794
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
static vector<int> ivec;
int main() {
    int n;
    scanf("%d", &n);
    ivec.resize(n);
    for (int i = 0; i < n; i++) scanf("%d", &ivec[i]);
    sort(ivec.begin(), ivec.end());
    ivec.resize(distance(ivec.begin(), unique(ivec.begin(), ivec.end())));
    if (ivec.size() < 2) puts("NO");
    else printf("%d\n", ivec[1]);
}