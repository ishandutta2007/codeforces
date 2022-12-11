#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

const int inf = 1e9 + 100;

struct node
{
    int minn;
    node* left;
    node* right;
    int promise;
    node() : left(nullptr), right(nullptr), promise(-1) {}
};

const int rmax = 20;
const int nmax = 100500;
int sparse[nmax][rmax];
int degs[nmax];
int n;

int getMin(int l, int r)
{
    int len = r - l + 1;
    int k = degs[len];
    return min(sparse[l][k], sparse[l + len - (1 << k)][k]);
}

int solve(int l, int r)
{
    int len = r - l + 1;
    if (len >= n) {
        return getMin(0, n - 1);
    }
    l %= n, r %= n;
    if (l <= r) {
        return getMin(l, r);
    } else {
        return min(getMin(l, n - 1), getMin(0, r));
    }
}

node* root = new node();

void build(node* v, int tl, int tr, int l, int r)
{
    if (tl == tr) {
        v->minn = getMin(l, l);
        //cerr << "?! " << v->minn << endl;
        return;
    }
    int tm = (tl + tr) >> 1;
    if (l <= tm) {
        v->left = new node();
        build(v->left, tl, tm, l, min(r, tm));
    } else {
        v->left = new node();
        v->left->minn = solve(tl, tm);
    }
    if (r > tm) {
        v->right = new node();
        build(v->right, tm + 1, tr, max(l, tm + 1), r);
    } else {
        v->right = new node();
        v->right->minn = solve(tm + 1, tr);
    }
    v->minn = min(v->left->minn, v->right->minn);
}

void push(node* v, int tl, int tr)
{
    int tm = (tl + tr) >> 1;
    if (v->left == nullptr) {
        v->left = new node();
        v->left->minn = solve(tl, tm);
    }
    if (v->right == nullptr) {
        v->right = new node();
        v->right->minn = solve(tm + 1, tr);
    }
    if (v->promise == -1) {
        return;
    }
    v->left->minn = v->promise;
    v->left->promise = v->promise;
    v->right->minn = v->promise;
    v->right->promise = v->promise;
    v->promise = -1;
}

void update(node* v, int tl, int tr, int l, int r, int val)
{
    if (tl == l && tr == r) {
        v->minn = val;
        v->promise = val;
        return;
    }
    push(v, tl, tr);
    int tm = (tl + tr) >> 1;
    if (l <= tm) {
        update(v->left, tl, tm, l, min(r, tm), val);
    }
    if (r > tm) {
        update(v->right, tm + 1, tr, max(l, tm + 1), r, val);
    }
    v->minn = min(v->right->minn, v->left->minn);
}

int get(node* v, int tl, int tr, int l, int r)
{
    //cerr << tl << " " << tr << " " << l << " " << r << endl;
    if (tl == l && tr == r) {
        //cerr << "!" << v->minn << " " << tl << " " << tr << " " << l << " " << r << endl;
        return v->minn;
    }
    push(v, tl, tr);
    //cerr << "AGA" << endl;
    int tm = (tl + tr) >> 1;
    int ans = inf;
    if (l <= tm) {
        ans = min(ans, get(v->left, tl, tm, l, min(r, tm)));
    }
    if (r > tm) {
        ans = min(ans, get(v->right, tm + 1, tr, max(l, tm + 1), r));
    }
    return ans;
}

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("f.out");
	//freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	degs[0] = -1;
    for (int i = 1; i < nmax; ++i) {
        degs[i] = degs[i - 1];
        if (!(i & (i - 1))) {
            ++degs[i];
        }
    }

    int k;
    cin >> n >> k;
    int b[nmax];

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        sparse[i][0] = b[i];
    }
    for (int r = 0; r + 1 < rmax; ++r) {
        for (int i = 0; i < n; ++i) {
            int t = min(i + (1 << r), n - 1);
            sparse[i][r + 1] = min(sparse[i][r], sparse[t][r]);
        }
    }

    root->minn = getMin(0, n - 1);
    int N = n * k;
    //cerr << N << endl;
    build(root, 0, N - 1, 0, n - 1);

    int q;
    cin >> q;

    while (q--) {
        int type;
        cin >> type;
        //cerr << type << endl;
        if (type == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            --l, --r;
            update(root, 0, N - 1, l, r, x);
        } else {
            int l, r;
            cin >> l >> r;
            --l, --r;
            cout << get(root, 0, N - 1, l, r) << endl;
        }
    }

}