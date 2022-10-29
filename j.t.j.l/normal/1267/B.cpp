#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

char s[300100];
int N;
vector<pii>seg;

int main() {
    scanf("%s",s + 1);
    N = strlen(s + 1);
    int nowcolor = s[1], nowlen = 1;
    for (int i=1;i<=N;i++) {
        if (i == N || s[i] != s[i + 1]) {
            seg.push_back(pii(nowcolor, nowlen));
            nowcolor = s[i + 1];
            nowlen = 1;
        } else {
            nowlen++;
        }
    }
    /*
    for (auto t:seg) {
        printf("%d %d\n",t.first,t.second);
    }
    */
    int M = seg.size();
    if (M % 2 == 0) {
        puts("0");
        return 0;
    }
    int mid = M / 2;
    for (int i=1;i<=mid;i++) {
        if (seg[mid + i].first != seg[mid - i].first || seg[mid + i].second + seg[mid - i].second < 3) {
            puts("0");
            return 0;
        }
    }
    if (seg[mid].second < 2) {
        puts("0");
    } else {
        printf("%d\n",seg[mid].second + 1);
    }
    return 0;
}