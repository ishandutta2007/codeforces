#include <cstdio>
#include <algorithm>

using namespace std;

int a, b;
int cnt[10];

int main(){
    scanf("%d%d", &a, &b);
    while (a % 2 == 0){a /= 2; ++cnt[2];}
    while (a % 3 == 0){a /= 3; ++cnt[3];}
    while (a % 5 == 0){a /= 5; ++cnt[5];}
    while (b % 2 == 0){b /= 2; --cnt[2];}
    while (b % 3 == 0){b /= 3; --cnt[3];}
    while (b % 5 == 0){b /= 5; --cnt[5];}
    if (a != b){printf("-1\n"); return 0;}
    printf("%d\n", abs(cnt[2]) + abs(cnt[3]) + abs(cnt[5]));
    return 0;
}