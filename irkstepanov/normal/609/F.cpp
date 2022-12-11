#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef unsigned int uuint;
typedef long long ll;
typedef pair<uuint, ll> pll;

const ll maxR = static_cast<ll>((1 << 30) - 1);

struct node
{
    uuint tl, tr;
    int frogId;
    node *left, *right;
    node(uuint newTl, uuint newTr)
        : tl(newTl)
        , tr(newTr)
        , left(NULL)
        , right(NULL)
        , frogId(-1)
    {}
    void clearNode()
    {
        if (left != NULL) {
            left->clearNode();
        }
        if (right != NULL) {
            right->clearNode();
        }
        delete this;
    }
};

struct frog
{
    uuint pos;
    ll len;
    int id, eaten;
    bool operator<(const frog& other) const
    {
        return pos < other.pos;
    }
};

vector<frog> frogs;
multiset<pll> mosquitos;

void create(node* v, uuint l, uuint r, int id)
{
    if (l > r) {
        return;
    }
    if (v->tl == l && v->tr == r) {
        v->frogId = id;
        if (v->left != NULL) {
            v->left->clearNode();
            v->left = NULL;
        }
        if (v->right != NULL) {
            v->right->clearNode();
            v->right = NULL;
        }
        return;
    }
    uuint tm = (v->tl + v->tr) >> 1;
    if (v->left == NULL) {
        node* left = new node(v->tl, tm);
        v->left = left;
    }
    create(v->left, l, min(r, tm), id);
    if (v->right == NULL) {
        node* right = new node(tm + 1, v->tr);
        v->right = right;
    }
    create(v->right, max(l, tm + 1), r, id);
}

node *root = new node(0, static_cast<uuint>(maxR));

void update(node* v, uuint l, uuint r, int id)
{
    if (l > r) {
        return;
    }
    if (v->tl == l && v->tr == r) {
        v->frogId = id;
        if (v->left != NULL) {
            v->left->clearNode();
            v->left = NULL;
        }
        if (v->right != NULL) {
            v->right->clearNode();
            v->right = NULL;
        }
        return;
    }
    uuint tm = (v->tl + v->tr) >> 1;
    if (v->left == NULL) {
        node *left = new node(v->tl, tm);
        v->left = left;
    }
    update(v->left, l, min(r, tm), id);
    if (v->right == NULL) {
        node *right = new node(tm + 1, v->tr);
        v->right = right;
    }
    update(v->right, max(l, tm + 1), r, id);
}

int add(node* v, uuint pos, int f)
{
    if (v->frogId != -1) {
        if (f == -1 || v->frogId < f) {
            f = v->frogId;
        }
    }
    if (v->tl == v->tr) {
        return f;
    }
    uuint tm = (v->tl + v->tr) >> 1;
    if (v->left != NULL && pos <= tm) {
        return add(v->left, pos, f);
    }
    if (v->right != NULL && pos > tm) {
        return add(v->right, pos, f);
    }
    return f;
}

int main()
{

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int cntFrogs, cntInsects;
    scanf("%d%d", &cntFrogs, &cntInsects);

    frogs.resize(cntFrogs);

    forn(i, cntFrogs) {
        int pos;
        scanf("%d%I64d", &pos, &frogs[i].len);
        frogs[i].pos = static_cast<uuint>(pos);
        frogs[i].id = i;
        frogs[i].eaten = 0;
    }

    sort(all(frogs));
    for (int i = cntFrogs - 1; i >= 0; --i) {
        ll x = static_cast<ll>(frogs[i].pos) + frogs[i].len;
        x = min(x, maxR);
        create(root, frogs[i].pos, static_cast<uuint>(x), i);
    }

    /*if (cntFrogs == 200000 && cntInsects == 200000) {
        return 0;
    }*/

    forn(i, cntInsects) {
        int intPos;
        ll size;
        scanf("%d%I64d", &intPos, &size);
        uuint pos = static_cast<uuint>(intPos);
        int f = add(root, pos, -1);
        if (f == -1) {
            mosquitos.insert({pos, size});
        } else {
            int id = f;
            ll xOld = static_cast<ll>(frogs[id].pos) + frogs[id].len + 1;
            xOld = min(xOld, maxR);
            frogs[id].len += size;
            ++frogs[id].eaten;
            ll x = static_cast<ll>(frogs[id].pos) + frogs[id].len;
            x = min(x, maxR);
            pll tmp = {xOld, -1};
            multiset<pll>::iterator it = mosquitos.lower_bound(tmp);
            multiset<pll>::iterator start = it;
            while (it != mosquitos.end() && it->first <= x) {
                x += it->second;
                frogs[id].len += it->second;
                ++frogs[id].eaten;
                x = min(x, maxR);
                ++it;
            }
            update(root, static_cast<uuint>(xOld), x, id);
            while (start != it) {
                multiset<pll>::iterator next = start;
                ++next;
                mosquitos.erase(start);
                start = next;
            }
        }
    }

    vector<int> eaten(cntFrogs);
    vector<ll> len(cntFrogs);
    forn(i, cntFrogs) {
        eaten[frogs[i].id] = frogs[i].eaten;
        len[frogs[i].id] = frogs[i].len;
    }

    forn(i, cntFrogs) {
        printf("%d %I64d\n", eaten[i], len[i]);
    }

}