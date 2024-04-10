#include <cstdio>
using namespace std;
bool found[100000];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0, j = n - 1; i < n; i++) {
        int x;
        scanf("%d", &x);
        x--;
        found[x] = true;

        bool first = true;
        while(j >= 0 && found[j]) {
            if(first)
                first = false;
            else
                putchar(' ');
            printf("%d", j + 1);
            j--;
        }

        putchar('\n');
    }
}