#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

constexpr int hashcode(const char* s, int n) {
    return n ? hashcode(s + 1, n - 1) * 27 + (*s - 'a' + 1) : 0;
}

vector<int> occu[hashcode("zzzz", 4) + 1];

char s[50001];

map<pair<int, int>, int> memo;

int query(char* a, char* b) {
    int la = strlen(a), lb = strlen(b);
    int ha = hashcode(a, la), hb = hashcode(b, lb);
    if(memo.count(minmax(ha, hb)))
        return memo[minmax(ha, hb)];

    const vector<int> &va = occu[ha], &vb = occu[hb];
    auto ia = va.begin(), ib = vb.begin();
    int mini = -1;
    while(ia != va.end() && ib != vb.end()) {
        int ln = max(*ia + la, *ib + lb) - min(*ia, *ib);
        if(mini == -1 || mini > ln)
            mini = ln;
        if(*ia < *ib) ++ia;
        else ++ib;
    }
    return memo[minmax(ha, hb)] = mini;
}

int main(){
    scanf("%s", s);
    int len = strlen(s);
    for(int i = 1; i <= 4; i++)
        for(int j = 0; j + i <= len; j++)
            occu[hashcode(s + j, i)].push_back(j);
    int q;
    scanf("%d", &q);
    while(q--) {
        char a[5], b[5];
        scanf("%s %s", a, b);
        printf("%d\n", query(a, b));
    }
}