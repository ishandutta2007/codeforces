#include <cstdio>
#include <cstdlib>
using namespace std;
bool get(int x) {
    printf("%d\n", x);
    fflush(stdout);
    char s[4];
    scanf("%s", s);
    return *s == 'y';
}
void answer(bool b) {
    puts(b ? "prime" : "composite");
    fflush(stdout);
    exit(0);
}
bool isp(int x) {
    for(int i = 2; i * i <= x; i++)
        if(x % i == 0)
            return false;
    return true;
}
int main() {
    int cnt = 0;
    for(int i = 2, j = 0; j < 19; i++)
        if(isp(i)) {
            if(get(i)) {
                cnt++;
                if(cnt == 1 && i * i <= 100 && get(i * i))
                    answer(false);
                else if(cnt == 2)
                    answer(false);
            }
            j++;
        }
    answer(true);
}