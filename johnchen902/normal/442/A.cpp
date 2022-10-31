#include <cstdio>
#include <algorithm>
#include <utility>
#include <bitset>
using namespace std;

int n;
pair<char, int> card[100];
bool ok[100][100];

bool is_ok(int mask) {
    for(int i = 0; i < n; i++)
        fill_n(ok[i], n, true);
    for(int i = 0; i < 10; i++) {
        if((mask >> i) & 1) { // told
            for(int j = 0; j < n; j++)
                for(int k = 0; k < n; k++) {
                    if(i < 5) { // RGBYW
                        if((card[j].first == "RGBYW"[i]) != (card[k].first == "RGBYW"[i]))
                            ok[j][k] = false;
                    } else { // 12345
                        if((card[j].second == i - 4) != (card[k].second == i - 4))
                            ok[j][k] = false;
                    }
                }
        }
    }
    return all_of(ok, ok + n, [](const bool* b){ return count(b, b + n, true) == 1; });
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        char buf[3];
        scanf("%s", buf);
        card[i] = {buf[0], buf[1] - '0'};
    }
    sort(card, card + n);
    n = unique(card, card + n) - card;
    int mini = 10;
    for(int i = 0; i < 1024; i++) {
        if(is_ok(i)) {
            mini = min(mini, (int) bitset<10>(i).count());
        }
    }
    printf("%d\n", mini);
}