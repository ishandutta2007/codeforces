#include <bits/stdc++.h>
using namespace std;

#ifdef D
#define deb printf
#define logg(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    vars += ",";
    int pos1 = 0, pos2 = vars.find(',');
    ((cout << vars.substr(pos1, pos2-pos1) << ": " << values, pos1 = pos2, pos2 = vars.find(',', pos2+1)), ...);
    cout << endl;
}
#else
#define deb(...)
#define logg(...)
#endif
#define BOOST ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
#define pb push_back

typedef long long int ll;
typedef long double ld;

const int N = 2e5+5;
const int LC = 1 << 19; // 524 288, bo kazdy odcinek ma 2 konce

int n;
int seg[N][2];
vector<vector<int>> evs;
int ans[N];
int tree[2*LC];

void tree_add (int index) {
    index += LC;
    while (index >= 1) {
        tree[index]++;
        index >>= 1;
    }
}

int tree_ask (int a, int b, int l = 0, int r = LC-1, int index = 1) {
    if (a == l and b == r)
        return tree[index];

    int srodek = (l + r) / 2;
    int res = 0;
    if (a <= srodek) {
        res += tree_ask(a, min(srodek, b), l, srodek, 2*index);
    }
    if (b > srodek) {
        res += tree_ask(max(srodek+1, a), b, srodek+1, r, 2*index+1);
    }

    return res;
}

int main () {
    scanf("%d", &n);
    // { pozycja, pocz/kon = 0/1, nr seg }
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &seg[i][0], &seg[i][1]);
        evs.pb({ seg[i][0], 0, i });
        evs.pb({ seg[i][1], 1, i });
    }

    sort(evs.begin(), evs.end());

    // przenumerowanie
    for (int i = 0; i < (int)evs.size(); i++) {
        evs[i][0] = i;
        seg[evs[i][2]][evs[i][1]] = i;
    }

    for (int i = (int)evs.size()-1; i >= 0; i--) {
        if (evs[i][1] == 0) {
            ans[evs[i][2]] = tree_ask(evs[i][0], seg[evs[i][2]][1]);
            tree_add(seg[evs[i][2]][1]);
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}