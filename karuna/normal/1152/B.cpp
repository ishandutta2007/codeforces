#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int x;
bool check(int x) {
    while (x) {
        if (x%2==0) return false;
        x/=2;
    }
    return true;
}
int main() {
    scanf("%d", &x);

    int t=0;
    vector<int> v;
    while (1) {
        if (check(x)==true) break;
        ++t;
        if (t%2) {
            int cnt = 0, tmp = x-1;
            while (tmp) {
                tmp/=2;
                ++cnt;
            }

            x ^= (1<<cnt)-1;
            v.push_back(cnt);
        }
        else {
            ++x;
        }
    }

    printf("%d\n", t);
    for (auto i : v) {
        printf("%d ", i);
    }
}