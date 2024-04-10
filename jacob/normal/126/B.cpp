#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

char s[1000001];

int main(void) {
    scanf("%s", s);
    int n = (int) strlen(s);
    vector<int> pi (n);
    int maxvmid = 0;
    for (int i=1; i<n; ++i) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])  ++j;
        pi[i] = j;
        if (i < n - 1) {
            maxvmid = max(maxvmid, j);
        }
    }
    int res = pi[n-1];
    while (res > maxvmid) {
        res = pi[res-1];
    }
    if (res == 0) {
        printf("Just a legend\n");
    } else {
        s[res] = 0;
        printf("%s\n", s);
    }
    return 0;
}