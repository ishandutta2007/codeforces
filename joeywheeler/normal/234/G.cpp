#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<vector<int> > comp_list;

comp_list c[1005];

template<class T>
void append(vector<T> &dest, vector<T> &src) {
    for (int i = 0; i < src.size(); i++) {
        dest.push_back(src[i]);
    }
}

comp_list base(int r) {
    if (r == 1) {
        return comp_list();
    } else if (c[r].size() != 0) {
        return c[r];
    } else {
        comp_list res;
        int mid = (1 + r) / 2;

        res.push_back(vector<int>());
        for (int i = 1; i <= mid; i++) res[0].push_back(i);

        comp_list a = base(mid);
        comp_list b = base(r-mid);
        for (int i = 0; i < b.size(); i++) {
            for (int j = 0; j < b[i].size(); j++) {
                b[i][j] += mid;
            }
            append(a[i], b[i]);
        }
        append(res, a);

        return c[r] = res;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    comp_list l = base(n);
    printf("%d\n", l.size());
    for (int i = 0; i < l.size(); i++) {
        printf("%d ", l[i].size());
        for (int j = 0; j < l[i].size(); j++) {
            printf("%d ", l[i][j]);
        }
        printf("\n");
    }
}