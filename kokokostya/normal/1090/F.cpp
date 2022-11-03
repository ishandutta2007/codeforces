#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

//#define FAST_ALLOCATOR_MEMORY 2e8
//#include "optimization.h"

using namespace std;

#define ALL(x) x.begin(), x.end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;

const int inf = (int)1e9;
const ll md = (ll)1e9 + 7, inf64 = (ll)1e18;

vector<int> ans(1000 + 7);

int ask(int a, int b, int c){
    cout << "? " << a + 1 << ' ' << b + 1 << ' ' << c + 1 << endl;
    int val;
    cin >> val;
    return val;
}

struct que{
    int a, b, c, val;
};

int fnd(vector<que>& a, vector<int> b){
    sort(b.begin(), b.end());
    for(int i = 0; i < (int)a.size(); i++) {
        if (b == vector<int>({a[i].a, a[i].b, a[i].c}))
            return a[i].val;
    }
    assert(false);
    return 0;
}

bool check(vector<que>& a, vector<int> c){
    for(auto& x : a){
        if(max(c[x.a], max(c[x.b], c[x.c])) + min(c[x.a], min(c[x.b], c[x.c])) != x.val)
            return 0;
    }
    return 1;
}

void solve(int l) {
    vector<int> p(5);
    for (int i = 0; i < 5; i++)
        p[i] = i;
    vector<que> a;
    for (int i = 0; i < 5; i++) {
    for (int j = i + 1; j < 5; j++)
        for (int k = j + 1; k < 5; k++)
            a.push_back({i, j, k, ask(i + l, j + l, k + l)});
    }
    vector<int> c(5, -1);

    do{
        int A1 = fnd(a, {p[0], p[1], p[4]});
        int A2 = fnd(a, {p[0], p[1], p[2]});
        int A3 = fnd(a, {p[2], p[3], p[4]});
        int A4 = fnd(a, {p[1], p[2], p[4]});
        int A5 = fnd(a, {p[0], p[2], p[3]});

        c[p[2]] = (A2 + A3 - A1) / 2;
        c[p[0]] = A2 - c[p[2]];
        c[p[4]] = A3 - c[p[2]];
        c[p[1]] = A4 - c[p[4]];
        c[p[3]] = A5 - c[p[0]];
        if(check(a, c)) break;
    }while(next_permutation(p.begin(), p.end()));
    for(int i = 0; i < 5; i++)
        ans[i + l] = c[i];
}

int main() {
    iostream::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

#ifdef LOCAL
    freopen("C:\\Users\\aytel\\CLionProjects\\common\\input.txt", "r", stdin);
    //freopen("C:\\Users\\aytel\\CLionProjects\\common\\output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for(int i = 0; i < n; i += 5){
        int r = min(n, i + 5);
        int l = r - 5;
        //[l, r)
        solve(l);
    }
    cout << "! ";
    for(int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}