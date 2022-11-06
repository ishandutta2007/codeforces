#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
struct Node {
    int lams = 0;
    int lamb = 0;
    int rams = 0;
    int ramb = 0;
    int maxup = 0;
    int maxdown = 0;
    int lmaxup = 0;
    int lmaxdown = 0;
    int rmaxdown = 0;
    int rmaxup = 0;
    bool reversed = false;
};
Node t[2000007];

ostream& operator<<(ostream& out, Node a) {
    out << "Left <: " << a.lams << '\n';
    out << "Left >: " << a.lamb << '\n';
    out << "Right <: " << a.rams << '\n';
    out << "Right >: " << a.ramb << '\n';
    out << "Max up: " << a.maxup << '\n';
    out << "Max down: " << a.maxdown << '\n';
    out << "Left max down: " << a.lmaxdown << '\n';
    out << "Left max up: " << a.lmaxup << '\n';
    out << "Right max down: " << a.rmaxdown << '\n';
    out << "Right max up: " << a.rmaxup << '\n';
    return out;
}

Node rev(Node a) {
    swap(a.lams, a.lamb);
    swap(a.rams, a.ramb);
    swap(a.maxup, a.maxdown);
    swap(a.lmaxup, a.lmaxdown);
    swap(a.rmaxdown, a.rmaxup);
    return a;
}
void push(int now, int l, int r) {
    if(!t[now].reversed) {
        return;
    }
    t[now].reversed = false;
    t[now] = rev(t[now]);
    if(l != r) {
        t[now * 2].reversed = !t[now * 2].reversed;
        t[now * 2 + 1].reversed = !t[now * 2 + 1].reversed;
    }
}

Node join(Node a, int lenl, Node b, int lenr) {
    Node res;
    res.lams = a.lams;
    if(a.lams == lenl) {
        res.lams += b.lams;
    }
    res.lamb = a.lamb;
    if(a.lamb == lenl) {
        res.lamb += b.lamb;
    }
    res.rams = b.rams;
    if(b.rams == lenr) {
        res.rams += a.rams;
    }
    res.ramb = b.ramb;
    if(b.ramb == lenr) {
        res.ramb += a.ramb;
    }

    res.maxup = max(a.maxup, b.maxup);
    res.maxup = max(res.maxup, a.rmaxup + b.lamb);
    res.maxup = max(res.maxup, a.rams + b.lmaxup);
    res.maxdown = max(a.maxdown, b.maxdown);
    res.maxdown = max(res.maxdown, a.rmaxdown + b.lams);
    res.maxdown = max(res.maxdown, a.ramb + b.lmaxdown);

    res.lmaxdown = a.lmaxdown;
    if(a.lmaxdown == lenl) {
        res.lmaxdown += b.lams;
    }
    res.lmaxdown = max(res.lmaxdown, max(res.lams, res.lamb));
    if(a.lamb == lenl) {
        res.lmaxdown = max(res.lmaxdown, b.lmaxdown + lenl);
    }

    res.lmaxup = a.lmaxup;
    if(a.lmaxup == lenl) {
        res.lmaxup += b.lamb;
    }
    res.lmaxup = max(res.lmaxup, max(res.lams, res.lamb));
    if(a.lams == lenl) {
        res.lmaxup = max(res.lmaxup, b.lmaxup + lenl);
    }


    res.rmaxup = b.rmaxup;
    if(b.rmaxup == lenr) {
        res.rmaxup += a.rams;
    }
    res.rmaxup = max(res.rmaxup, max(res.rams, res.ramb));
    if(b.ramb == lenr) {
        res.rmaxup = max(res.rmaxup, a.rmaxup + lenr);
    }


    res.rmaxdown = b.rmaxdown;
    if(b.rmaxdown == lenr) {
        res.rmaxdown += a.ramb;
    }
    res.rmaxdown = max(res.rmaxdown, max(res.rams, res.ramb));
    if(b.rams == lenr) {
        res.rmaxdown = max(res.rmaxdown, a.rmaxdown + lenr);
    }

    return res;
}

void build_tree(int now, int l, int r, string& s) {
    if(l == r) {
        t[now].lams = 1;
        t[now].rams = 1;
        t[now].maxup = 1;
        t[now].maxdown = 1;
        t[now].lmaxdown = 1;
        t[now].lmaxup = 1;
        t[now].rmaxup = 1;
        t[now].rmaxdown = 1;
        if(s[l] == '>') {
            t[now] = rev(t[now]);
        }
        return;
    }
    int mid = (l + r) / 2;
    build_tree(now * 2, l, mid, s);
    build_tree(now * 2 + 1, mid + 1, r, s);
    t[now] = join(t[now * 2], mid - l + 1, t[now * 2 + 1], r - mid);
    //cout << l << ' ' << r << endl;
    //cout << t[now] << endl << endl;
}

void reverse_t(int now, int l, int r, int l1, int r1) {
    push(now, l, r);
    if(l > r1 || l1 > r) {
        return;
    }
    if(l1 <= l && r <= r1) {
        t[now].reversed = true;
        push(now, l, r);
        return;
    }
    int mid = (l + r) / 2;
    reverse_t(now * 2, l, mid, l1, r1);
    reverse_t(now * 2 + 1, mid + 1, r, l1, r1);
    t[now] = join(t[now * 2], mid - l + 1, t[now * 2 + 1], r - mid);
}
Node get_ans(int now, int l, int r, int l1, int r1) {
    push(now, l, r);
    if(l > r1 || l1 > r) {
        Node a;
        return a;
    }
    if(l1 <= l && r <= r1) {
        return t[now];
    }
    int mid = (l + r) / 2;
    return join(get_ans(now * 2, l, mid, l1, r1), mid - l + 1, get_ans(now * 2 + 1, mid + 1, r, l1, r1), r - mid);
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    build_tree(1, 0, n - 1, s);
    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        reverse_t(1, 0, n - 1, l, r);
        cout << get_ans(1, 0, n - 1, l, r).maxdown << '\n';
    }
}