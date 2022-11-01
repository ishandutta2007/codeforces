#include <cstdio>
#include <set>
using namespace std;
set<int> s;
bool cantest(int x) {
    if(x < 0)
        return false;
    for(int i : s)
        if(s.count(i + x))
            return true;
    return false;
}
int main(){
    int n, l, x, y;
    scanf("%d %d %d %d", &n, &l, &x, &y);
    for(int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        s.insert(a);
    }
    if(cantest(x) && cantest(y)) {
        puts("0");
        return 0;
    }
    if(cantest(x)) {
        printf("1\n%d\n", y);
        return 0;
    }
    if(cantest(y)) {
        printf("1\n%d\n", x);
        return 0;
    }
    for(int i : s)
        if(s.count(i + x + y)) {
            printf("1\n%d\n", i + x);
            return 0;
        }
    for(int i : s)
        if(s.count(i - x + y) && i + y <= l) {
            printf("1\n%d\n", i + y);
            return 0;
        } else if(s.count(i - x + y) && i - x >= 0) {
            printf("1\n%d\n", i - x);
            return 0;
        }
    printf("2\n%d %d\n", x, y);
}