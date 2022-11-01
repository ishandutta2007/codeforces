#include <cstdio>
#include <map>
using namespace std;
int bit[1 << 20]; static_assert(1 << 20 >= 1000000, "small");
void add(int x) {
    x++;
    while(x <= 1 << 20) {
        bit[x - 1]++;
        x += x & -x;
    }
}
int query(int x) {
    int v = 0;
    while(x) {
        v += bit[x - 1];
        x -= x & -x;
    }
    return v;
}
int a[1000000];
int l[1000000];
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", a + i);
    {
        map<int, int> ms;
        for(int i = 0; i < n; i++)
            l[i] = ++ms[a[i]];
    }
    long long cnt = 0;
    {
        map<int, int> ms;
        for(int i = n - 1; i >= 0; i--) {
            cnt += query(l[i]);
            add(++ms[a[i]]);
        }
    }
    printf("%I64d\n", cnt);
}