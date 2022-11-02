#include <bits/stdc++.h>

const int N = 500005;

struct bian {
    int next, point;
} b[N];

int n, Len, Whr, Now;
int p[N], Size[N], A[N];

void Ade(int k1, int k2) { b[++Len] = (bian){p[k1], k2}, p[k1] = Len; }

void Add(int k1, int k2) { Ade(k1, k2), Ade(k2, k1); }

void Dfs(int k1, int k2) {
    Size[k1] = 1;
    int num = 0;
    for (int i = p[k1]; i; i = b[i].next) {
        int j = b[i].point;
        if (j != k2) {
            Dfs(j, k1);
            num = std::max(num, Size[j]);
            Size[k1] += Size[j];
        }
    }
    num = std::max(num, n - Size[k1]);
    A[k1] = num;
}

struct Atom {
    int x, y, aim;
    void print() { printf("%d %d %d\n", x, y, aim); }
};

std::vector<Atom> ans;

int pre = 0;

void getans(int k1, int k2, int aim, int root) {
    if (root != k1) {
        ans.push_back((Atom){aim, pre, k1});
        ans.push_back((Atom){k1, k2, root});
        pre = k1;
    }
    for (int i = p[k1]; i; i = b[i].next) {
        int j = b[i].point;
        if (j != k2) getans(j, k1, aim, root);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int k1, k2;
        scanf("%d%d", &k1, &k2);
        Add(k1, k2);
    }
    int m = 0;
    Dfs(1, 0);
    for (int Now = 1; Now <= n; ++Now) {
        if (A[Now] <= n / 2) {
            for (int i = p[Now]; i; i = b[i].next) {
                int j = b[i].point;
                pre = j;
                if (A[j] > n / 2) {
                    getans(j, Now, Now, j);
                    ans.push_back((Atom){Now, pre, j});
                }
            }
        }
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); ++i) ans[i].print();
    return 0;
}