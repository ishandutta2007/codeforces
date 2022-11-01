#include <cstdio>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
using namespace std;
vector<int> ch[1000000];
int t[1000000], sum[1000000];
int cut1, cut2;
int dfs(int v, int root, int target) {
    sum[v] = t[v];
    int status = 0;
    for(int c : ch[v]) {
        status += dfs(c, root, target);
        sum[v] += sum[c];
    }
    if(v != root && cut2 == -1) {
        if(status == 0 && sum[v] == target) {
            (cut1 == -1 ? cut1 : cut2) = v;
            status++;
        } else if(status == 1 && sum[v] == target * 2) {
            assert(cut1 >= 0);
            cut2 = v;
            status++;
        }
    }
    return status;
}
bool solve(int n, int root) {
    int sumt = accumulate(t, t + n, 0);
    if(sumt % 3)
        return false;
    cut1 = -1, cut2 = -1;
    int status = dfs(root, root, sumt / 3);
    if(status != 2)
        return false;
    printf("%d %d\n", cut1 + 1, cut2 + 1);
    return true;
}
int main() {
    int n;
    scanf("%d", &n);
    int root = -1;
    for(int i = 0; i < n; i++) {
        int p;
        scanf("%d %d", &p, t + i);
        p--;
        if(p == -1)
            root = i;
        else
            ch[p].push_back(i);
    }
    if(!solve(n, root))
        puts("-1");
}