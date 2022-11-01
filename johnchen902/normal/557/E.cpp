#include <cstdio>
#include <cstring>
using namespace std;

char s[5001];
bool hp[5000][5000];

struct Trie {
    Trie *a, *b;
    int cnt, sum;
    Trie() : a(nullptr), b(nullptr), cnt(0), sum(0) {}
    void compute_sum() {
        sum = cnt;
        if(a) a->compute_sum(), sum += a->sum;
        if(b) b->compute_sum(), sum += b->sum;
    }
} pool[5000 * 5001 / 2];
int psize;

void go(Trie * t, int k) {
    while(k > t->cnt) {
        k -= t->cnt;

        if(t->a) {
            if(k <= t->a->sum) {
                putchar('a');
                t = t->a;
                continue;
            } else
                k -= t->a->sum;
        }

        putchar('b');
        t = t->b;
    }
}

int main() {
    // read s
    gets(s);
    int n = strlen(s);

    // half palindrome
    for(int k = 0; k < n; k++)
        for(int i = 0; i + k < n; i++)
            hp[i][i + k] = s[i] == s[i + k] && (k < 4 || hp[i + 2][i + k - 2]);

    // trie
    Trie * root = pool + psize++;
    for(int i = 0; i < n; i++) {
        Trie * cur = root;
        for(int j = i; j < n; j++) {
            Trie * & next = s[j] == 'a' ? cur->a : cur->b;
            if(!next) next = pool + psize++;
            (cur = next)->cnt += hp[i][j];
        }
    }
    root->compute_sum();

    // read k
    int k;
    scanf("%d", &k);

    go(root, k);
    putchar('\n');
}