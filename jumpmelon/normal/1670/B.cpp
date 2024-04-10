#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000, M = 26;
char S[MAXN + 5];
int Sp[M + 5];

struct node {
    char ch;
    node *prev, *next;
    node *prevsp, *nextsp;
} head, Node[MAXN + 5];

void build(int n) {
    head = {0, &head, &head, &head, &head};
    node *prev = &head, *prevsp = &head;
    for (int i = 0; i < n; i++) {
        Node[i].ch = S[i];
        Node[i].prev = prev;
        prev = prev->next = &Node[i];
        if (Sp[S[i] - 'a']) {
            Node[i].prevsp = prevsp;
            prevsp = prevsp->nextsp = &Node[i];
        }
    }
    head.prev = prev;
    prev->next = &head;
    head.prevsp = prevsp;
    prevsp->nextsp = &head;
}

void erase(node *p) {
    node *prev = p->prev, *next = p->next;
    prev->next = next;
    next->prev = prev;
    if (Sp[p->ch - 'a']) {
        node *prevsp = p->prevsp, *nextsp = p->nextsp;
        prevsp->nextsp = nextsp;
        nextsp->prevsp = prevsp;
    }
}

int main() {
    int kase;
    scanf("%d", &kase);
    while (kase--) {
        int n, k;
        scanf("%d", &n);
        scanf("%s", S);
        scanf("%d", &k);
        memset(Sp, 0, sizeof(int[M]));
        while (k--) {
            char c;
            scanf(" %c", &c);
            Sp[c - 'a'] = 1;
        }
        build(n);
        int ans = 0;
        while (1) {
            int flag = 0;
            for (node *p = head.nextsp; p != &head; p = p->nextsp) {
                if (p->prev != &head) {
                    flag = 1;
                    erase(p->prev);
                }
            }
            if (flag) {
                ans++;
            } else {
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}