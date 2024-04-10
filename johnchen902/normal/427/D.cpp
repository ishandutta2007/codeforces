#include <cstdio>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <iterator>
using namespace std;
using namespace std::placeholders;

int n, n1, n2;
char s[10002];
int sa[10001];
int pos[10001];
int tmp[10001];

void read_input() {
    scanf("%s", s);
    n1 = strlen(s);
    s[n1] = '$';
    scanf("%s", s + n1 + 1);
    n2 = strlen(s + n1 + 1);
    n = n1 + 1 + n2;
}
struct Cmp {
    const int gap;
    Cmp(int g) : gap(g) {}
    bool operator () (int a, int b) const {
        if(pos[a] != pos[b]) return pos[a] < pos[b];
        a += gap; b += gap;
        return a < n && b < n ? pos[a] < pos[b] : a > b;
    }
};
void build_sa() {
    iota(sa, sa + n, 0);
    copy_n(s, n, pos);
    for(int gap = 1; ; gap <<= 1) {
        sort(sa, sa + n, Cmp(gap));
        for(int i = 0; i < n - 1; i++) tmp[i + 1] = tmp[i] + Cmp(gap)(sa[i], sa[i + 1]);
        for(int i = 0; i < n; i++) pos[sa[i]] = tmp[i];
        if(tmp[n - 1] == n - 1) break;
    }
}

int lcp[10001];
void build_lcp() {
    for(int i = 0, k = 0; i < n; i++) {
        if(pos[i] != n - 1) {
            for(int j = sa[pos[i] + 1]; s[i + k] == s[j + k]; k++)
                ;
            lcp[i] = k;
            if(k) k--;
        }
    }
}

// length of minimum unique prefix
int mup[10001];

int main(){
    read_input();
    build_sa();
    build_lcp();
    for(int i = 1, j[2] = {-1, -1}, lcp1[2] = {0, 0}; i < n; i++) {
        bool b = sa[i] < n1;
        mup[i] = lcp1[b] + 1;
        if(~j[b])
            mup[j[b]] = max(mup[j[b]], lcp1[b] + 1);
        j[b] = i;
        lcp1[b] = lcp[sa[i]];
        lcp1[!b] = min(lcp1[!b], lcp[sa[i]]);
    }
//    for(int i = 1; i < n; i++)
//        printf("%*s %d %d\n", n, s + sa[i], lcp[sa[i]], mup[i]);
    int mini = -1;
    for(int i = 0; i < n - 1; i++) {
        if((sa[i] < n1) != (sa[i + 1] < n1)) {
            int both_u = max(mup[i], mup[i + 1]);
            if(both_u <= lcp[sa[i]])
                if(mini == -1 || mini > both_u)
                    mini = both_u;
        }
    }
    printf("%d\n", mini);
}