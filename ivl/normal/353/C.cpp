#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int a[100005];

char m[100005];

int s[100005];

int sum(int lo, int hi){
    if (lo == 0) return s[hi];
    return s[hi] - s[lo - 1];
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + (n - i - 1));
    s[0] = a[0];
    for (int i = 0; i < n; ++i) s[i] = s[i - 1] + a[i];
    scanf("%s", m);
    for (int i = 0; i < n - i - 1; ++i) swap(m[i], m[n - i - 1]);
    int rez = 0, cs = 0;
    for (int i = 0; i < n; ++i){
        if (m[i] == '1'){
           rez = max(rez, cs + sum(i + 1, n - 1));
           cs += a[i];
        }
    }
    rez = max(rez, cs);
    printf("%d\n", rez);
    return 0;
}