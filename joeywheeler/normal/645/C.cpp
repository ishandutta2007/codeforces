#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

vector<int> p;
int n, k;
char s[100005];

bool can(int d) {
    for (int x : p) {
        int l = lower_bound(p.begin(), p.end(), x-d)-p.begin();
        int r = lower_bound(p.begin(), p.end(), x+d+1)-p.begin();
        if (r-l >= k+1) return true;
    }
    return false;
}

int main() {
    scanf("%d%d", &n, &k);
    scanf(" %s", s);
    FO(i,0,n) if (s[i] == '0') p.push_back(i);

    int st = 0, en = 200005, b = 200005;
    while (st <= en) {
        int md = (st+en)/2;
        if (can(md)) {
            b = md;
            en = md-1;
        } else {
            st = md+1;
        }
    }
    printf("%d\n", b);
}