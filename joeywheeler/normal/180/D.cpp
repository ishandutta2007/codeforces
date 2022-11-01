#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

bool can_do(string targ, string have) {
    reverse(have.begin(), have.end());
    return have > targ;
}

void solve(string targ, string have) {
    if (targ.size() == 0) {
        printf("%s", have.c_str());
    } else {
        bool tmp = true;
        for (int i = 0; i < have.size(); i++) {
            if (have[i] == targ[0] && tmp) {
                tmp = false;
                string remove = have.substr(0, i) + have.substr(i+1, have.size() - i - 1);
                if (can_do(targ.substr(1, have.size()-1), remove)) {
                    printf("%c", have[i]);
                    solve(targ.substr(1, have.size()-1), remove);
                    return;
                }
            } else if (have[i] > targ[0]) {
                printf("%c", have[i]);
                string remove = have.substr(0, i) + have.substr(i+1, have.size() - i - 1);
                printf("%s", remove.c_str());
                return;
            }
        }
    }
}

int main() {
    char targ[5005], have[5005];
    scanf(" %s %s ", have, targ);
    sort(have, have + strlen(have));
    if (can_do(targ, have)) solve(targ, have);
    else printf("-1");
}