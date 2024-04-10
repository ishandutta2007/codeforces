#include <bits/stdc++.h>
using namespace std;

#define K 1111111

char *words[K];
int lens[K];
char wordt[K];
vector<pair<int, int>> writes[2*K];
vector<pair<int, int>> unwrites[2*K];
int main() {
    int n;
    scanf("%d", &n);
    char *curr = wordt;
    int tlen = 0;
    for (int i = 0; i < n; i++) {
        words[i] = curr;
        scanf("%s", words[i]);
        lens[i] = strlen(words[i]);
        curr += lens[i];
        int w;
        scanf("%d", &w);
        while (w--) {
            int p;
            scanf("%d", &p);
            p--;
            tlen = max(tlen, p + lens[i]);
            writes[p].emplace_back(i, p);
            unwrites[p + lens[i]].emplace_back(i, p);
        }
    }
    multiset<pair<int,int>> ps;
    for (int p = 0; p < tlen; p++) {
        for (auto it : writes[p]) {
            ps.insert(it);
        }
        for (auto it : unwrites[p]) {
            ps.erase(ps.find(it));
        }
        char c = 'a';
        if (!ps.empty()) {
            auto it = *ps.begin();
            c = words[it.first][p - it.second];
        }
        printf("%c", c);
    }
    printf("\n");
}