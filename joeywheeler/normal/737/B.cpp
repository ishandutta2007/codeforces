#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, a, b, k;
char s[200005];

int main() {
    scanf("%d %d %d %d", &n, &a, &b, &k);
    scanf("%s", s);

    int tot = 0;
    vector<int> v;
    for (int i = 0; i < n; ) if (s[i] == '0') {
        int j;
        for (j = i; s[j] == '0'; j++);
        tot += (j-i)/b;
        FO(k,0,(j-i)/b) v.push_back(i+b*(k+1));
        i = j;
    } else i++;
    v.resize(tot-a+1);
    printf("%d\n", sz(v));
    for (int x : v) printf("%d ", x);
    printf("\n");
}