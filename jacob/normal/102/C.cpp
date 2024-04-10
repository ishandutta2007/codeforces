#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

char str[1000000];

int main(void) {
    scanf("%s", str);
    int n = (int)strlen(str);
    int k;
    scanf("%d", &k);
    if (k >= n) {
        printf("0\n\n");
        return 0;
    }
    vector<int> cnt(128);
    for (int i = 0; i < n; i++) {
        cnt[str[i]]++;
    }
    vector< pair<int, int> > v;
    for (int i = 0; i < 128; i++) {
        v.push_back(make_pair(cnt[i], i));
    }
    sort(v.begin(), v.end());
    vector<bool> hide(128);
    for (int i = 0; i < 128; i++) {
        if (k < v[i].first) {
            printf("%d\n", 128 - i);
            break;
        }
        k -= v[i].first;
        hide[v[i].second] = true;
    }
    for (int i = 0; i < n; i++) {
        if (!hide[str[i]])
            printf("%c", str[i]);
    }
    printf("\n");
    return 0;
}