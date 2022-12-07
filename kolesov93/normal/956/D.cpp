#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll myabs(ll x) {
    if (x < 0) return -x;
    return x;
}

int w;
struct cell {
    ll a, b;
    ll oa, ob;
    int num;
    int onum;

    cell(int a, int b, int i) : a(myabs(a)), b(myabs(b)), oa(a), ob(b), num(i) {}
};

bool cmp1(const cell& A, const cell& B) {
    ll diff = A.a * B.b - A.b * B.a;
    if (diff != 0) return diff < 0;
    //cerr << "!!" << A.oa << " " << A.ob << " " << B.oa << " " << B.ob << endl;

    diff = myabs(A.a) * myabs(B.ob + w) - myabs(A.ob + w) * myabs(B.a);
    //cerr << "!!" << diff << endl;
    if (diff != 0) return diff > 0;
    return A.num < B.num;
}
bool cmp2(const cell& A, const cell& B) {
    ll diff = A.a * B.b - A.b * B.a;
    if (diff != 0) return diff < 0;
    diff = myabs(A.a) * myabs(B.ob  - w) - myabs(A.ob - w) * myabs(B.a);
    if (diff != 0) return diff > 0;
    return A.num > B.num;
}

int prev(int x) {
    return x & (x - 1);
}
int nxt(int x) {
    return x + x - prev(x);
}
int findsum(vector<int>& s, int l, int r) {
    int ans = 0;
    for (++r; r; r = prev(r)) ans += s[r];
    for (; l; l = prev(l)) ans -= s[l];
    return ans;
}
void modify(vector<int>& s, size_t pos, int val) {
    for (++pos; pos < s.size(); pos = nxt(pos)) s[pos] += val;
}


int main() {
    int n;
    cin >> n >> w;
    vector<int> x(n), v(n);

    vector<cell> first_pass, second_pass;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &x[i], &v[i]);
        first_pass.emplace_back(x[i], v[i] - w, i);
        second_pass.emplace_back(x[i], v[i] + w, i);
        first_pass[i].onum = first_pass[i].num;
        second_pass[i].onum = second_pass[i].num;
    }
    sort(begin(first_pass), end(first_pass), cmp1);
    vector<int> i2pos(n);
    for (int i = 0; i < n; ++i) {
        second_pass[first_pass[i].num].num = i;
    }
    sort(begin(second_pass), end(second_pass), cmp2);
    /*
    for (int i = 0; i < n; ++i) {
        auto val = first_pass[i];
        cerr << i << ": " << val.a << "/" << val.b << " (" << val.num << ")" << endl;
    }
    cerr << endl;
    for (int i = 0; i < n; ++i) {
        auto val = second_pass[i];
        cerr << i << ": " << val.a << "/" << val.b << " (" << val.num << ")" << endl;
    }
    */

    vector<int> a(n);
    //cerr << "a:" << endl;
    for (int i = 0; i < n; ++i) {
        a[i] = second_pass[i].num;
        //cerr << " " << a[i];
    }
    //cerr << endl;

    vector<int> pos1(n), pos2(n);
    for (int i = 0; i < n; ++i) {
        pos1[first_pass[i].onum] = i;
        pos2[second_pass[i].onum] = i;
    }

    /*
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j) {
            if (pos1[i] < pos1[j]) {
                if (pos2[i] > pos2[j]) {
                    cout << i << " " << j << endl;
                }
            } else {
                if (pos2[i] < pos2[j]) {
                    cout << i << " " << j << endl;
                }
            }
        }
    */


    //cerr << pos1[10] << "-->" << pos2[10] << endl;
    //cerr << pos1[56] << "-->" << pos2[56] << endl;

    vector<int> s(n + 1);
    ll ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        ans += findsum(s, 0, a[i]);
        modify(s, a[i], 1);
    }
    cout << ans << endl;

    return 0;
}