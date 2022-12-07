#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

const int N = 50005;

int n, a;
set<int> s;
set<int>::iterator it;

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &a);
        s.insert(a);
    }
    while (s.size()) {
        it = s.end(); it--;
        int x = *it;
        int xx = x;
        int f = 0;
        while (x / 2) {
            x /= 2;
            if (s.find(x) == s.end()) {
                s.insert(x);
                f = 1;
                break;
            }
        }
        if (!f) printf("%d ", xx);
        s.erase(xx);
    }
    return 0;
}