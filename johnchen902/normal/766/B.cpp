#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[100000];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", a + i);
    sort(a, a + n);
    bool found = false;
    for(int i = 0; i + 2 < n; i++)
        if(a[i] + a[i + 1] > a[i + 2]) {
            found = true;
            break;
        }
    puts(found ? "YES" : "NO");
}