#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

static_assert(1 << 17 >= 100000, "small");

int main(){
    int n, q;
    scanf("%d %d", &n, &q);
    vector<pair<int, int>> paper = {{0, 1}, {n, 0}};
    while(q--) {
        int cmd;
        scanf("%d", &cmd);
        if(cmd == 1) {
            int p;
            scanf("%d", &p);
            int l = lower_bound(paper.begin(), paper.end(), make_pair(p, 99999999)) - paper.begin() - 1;
            int r = l + 1;
            vector<pair<int, int>> p2 = {{0, 0}};
            if(paper[l].first == p) l--;
            while(l >= 0 && r < (int) paper.size()) {
                p2.back().second = paper[l].second + paper[r - 1].second;
                if(p - paper[l].first == paper[r].first - p) {
                    p2.push_back({p - paper[l].first, 0});
                    l--, r++;
                } else if(p - paper[l].first < paper[r].first - p) {
                    p2.push_back({p - paper[l].first, 0});
                    l--;
                } else {
                    p2.push_back({paper[r].first - p, 0});
                    r++;
                }
            }
            while(l >= 0) {
                p2.back().second = paper[l].second;
                p2.push_back({p - paper[l].first, 0});
                l--;
            }
            while(r < (int) paper.size()) {
                p2.back().second = paper[r - 1].second;
                p2.push_back({paper[r].first - p, 0});
                r++;
            }
            p2.back().second = 0;
            paper = move(p2);
        } else {
            int l, r;
            scanf("%d %d", &l, &r);
            int sum = 0;
            for(int i = 0, j = 1; j < (int) paper.size(); i++, j++) {
                sum += max(0, min(r, paper[j].first) - max(l, paper[i].first)) * paper[i].second;
            }
            printf("%d\n", sum);
        }
    }
}