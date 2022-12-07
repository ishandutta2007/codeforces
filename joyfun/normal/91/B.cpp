#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100005;

struct ST {
    int age, id;

    void read(int id) {
        this->id = id;
        scanf("%d", &age);
    }

    bool operator < (const ST& c) const {
        if (age == c.age) return id < c.id;
        return age < c.age;
    }
} s[N];


int n, ans[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        s[i].read(i);
    sort(s + 1, s + 1 + n);
    int r = 0;
    for (int i = 1; i <= n; i++) {
        if (r < s[i].id) ans[s[i].id] = -1;
        else ans[s[i].id] = r - s[i].id - 1;
        r = max(r, s[i].id);
    }
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]); printf("\n");
    return 0;
}