#include <bits/stdc++.h>
using namespace std;

struct S
{
    char c;
    int cnt;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    vector<S> blocks;
    for (int i = 0; i < (int)s.size(); i++) {
        if (i == 0 || blocks.back().c != s[i]) {
            blocks.push_back({s[i], 1});
        } else {
            blocks.back().cnt++;
        }
    }

    int cnt = 0;
    while (blocks.size() > 1) {
        int ma = 999'999'999;
        for (int i = 0; i < (int)blocks.size(); i++) {
            if (i == 0 || i == (int)blocks.size() - 1) 
                ma = min(ma, blocks[i].cnt);
            else 
                ma = min(ma, blocks[i].cnt == 1 ? 1 : blocks[i].cnt / 2);
        }

        cnt += ma;
        for (int i = 0; i < (int)blocks.size(); i++) {
            blocks[i].cnt -= ma;
            if (i > 0 && i < (int)blocks.size() - 1)
                blocks[i].cnt -= ma;
        }

        vector<S> blocks2;
        for (auto& block : blocks) {
            if (block.cnt > 0) {
                if (blocks2.empty() || block.c != blocks2.back().c) {
                    blocks2.push_back(block);
                } else {
                    blocks2.back().cnt += block.cnt;
                }
            }
        }
        blocks.swap(blocks2);
    }

    cout << cnt << '\n';
    
}