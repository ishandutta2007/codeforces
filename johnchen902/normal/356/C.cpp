#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int s[5];

int solve() {
    int sum = s[1] + s[2] * 2 + s[3] * 3 + s[4] * 4;
    if(sum == 1 || sum == 2 || sum == 5) return -1;
    int best = sum;
    for(int save2 = 0; save2 <= s[2]; save2++) {
        int curr1 = s[1] + (s[2] - save2) * 2;
        if(save2 <= curr1 + s[4]) {
            int left1 = max(curr1 - save2, 0);
            int cost = (left1 * 2 + 2) / 3;
            if(left1 == 1 && save2 == 0 && s[3] == 0) cost++;
            best = min(best, cost + save2);
        }
    }
    return best;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        s[x]++;
    }
    printf("%d\n", solve());
}