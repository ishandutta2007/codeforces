#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
uniform_int_distribution<int> dst(0, 1000000000);
mt19937 rnd(1791791791);


int get_random()
{
    return dst(rnd);
}
struct Node
{
    Node* l = nullptr;
    Node* r = nullptr;
    pair<int, int> x;
    int y;
    pair<int, int> otr;
    ll value;
};

void update(Node* root)
{
    if(root == nullptr)
    {
        return;
    }
    int len = root->x.second - root->x.first + 1;
    root->value = (ll)len * (len + 1) / 2;
    root->otr = root->x;
    if(root->l != nullptr)
    {
        root->value += root->l->value;
        root->otr.first = min(root->otr.first, root->l->otr.first);
    }
    if(root->r != nullptr)
    {
        root->value += root->r->value;
        root->otr.second = max(root->otr.second, root->r->otr.second);
    }
}

pair<Node*, Node*> split(Node* root, pair<int, int> val)
{
    if(root == nullptr)
    {
        return {nullptr, nullptr};
    }
    if(root->x <= val)
    {
        auto p = split(root->r, val);
        root->r = p.first;
        update(root);
        return {root, p.second};
    }
    else
    {
        auto p = split(root->l, val);
        root->l = p.second;
        update(root);
        return {p.first, root};
    }
}

Node* merge(pair<Node*, Node*> roots)
{
    if(roots.first == nullptr)
    {
        return roots.second;
    }
    if(roots.second == nullptr)
    {
        return roots.first;
    }
    if(roots.first->y >= roots.second->y)
    {
        roots.first->r = merge({roots.first->r, roots.second});
        update(roots.first);
        return roots.first;
    }
    else
    {
        roots.second->l = merge({roots.first, roots.second->l});
        update(roots.second);
        return roots.second;
    }
}

Node* create_node(pair<int, int> x)
{
    Node* node = new Node();
    node->x = x;
    node->y = get_random();
    update(node);
    return node;
}

ll get_result(Node* root, int l, int r)
{
    if(root == nullptr)
    {
        return 0;
    }
    //cout << l << ' ' << r << ' ' << root->otr.first << ' ' << root->otr.second << endl;
    if(root->otr.first > r || root->otr.second < l)
    {
        return 0;
    }
    if(l <= root->otr.first && root->otr.second <= r)
    {
        return root->value;
    }
    ll res = 0;
    res += get_result(root->l, l, r);
    res += get_result(root->r, l, r);
    int l1 = max(l, root->x.first);
    int r1 = min(r, root->x.second);
    int len = max(0, r1 - l1 + 1);
    res += (ll)(len) * (len + 1) / 2;
    return res;
}

Node* erase1(Node* root, pair<int, int> x)
{
    auto p = split(root, x);
    --x.first;
    p.first = split(p.first, x).first;
    return merge(p);
}
Node* add1(Node* root, pair<int, int> x)
{
    auto need = create_node(x);
    auto p = split(root, x);
    p.first = merge({p.first, need});
    return merge(p);
}
set<pair<int, int> > s;
Node* root = nullptr;
pair<int, int> get_by_el(int i)
{
    auto it = s.lower_bound({i + 1, -1});
    --it;
    return *it;
}

void erase_if_can(int i)
{
    auto it = s.lower_bound({i + 1, -1});
    if(it == s.begin())
    {
        return;
    }
    --it;
    if((*it).first <= i && i <= (*it).second)
    {
        root = erase1(root, *it);
        s.erase(it);
    }
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
    vector<int> mass(n);
    int prev = 0;
    cin >> mass[0];
    for(int i = 1; i < n; i++)
    {
        cin >> mass[i];
        if(mass[i] < mass[i - 1])
        {
            s.insert({prev, i - 1});
            root = add1(root, {prev, i - 1});
            prev = i;
        }
    }
    s.insert({prev, n - 1});
    root = add1(root, {prev, n - 1});
    //cout << root->otr.first << ' ' << root->otr.second << endl;
    for(int _ = 0; _ < q; _++)
    {
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 2)
        {
            cout << get_result(root, a - 1, b - 1) << '\n';
        }
        else
        {
            --a;
            int left = get_by_el(max(0, a - 1)).first;
            int right = get_by_el(min(n - 1, a + 1)).second;
            erase_if_can(a);
            erase_if_can(left);
            erase_if_can(right);
            bool first = false;
            bool second = false;
            if(a == 0 || mass[a - 1] <= b)
            {
                first = true;
            }
            if(a == n - 1 || b <= mass[a + 1])
            {
                second = true;
            }
            if(second && first)
            {
                s.insert({left, right});
                root = add1(root, {left, right});
            }
            else if(first)
            {
                s.insert({left, a});
                root = add1(root, {left, a});
                s.insert({a + 1, right});
                root = add1(root, {a + 1, right});
            }
            else if(second)
            {
                s.insert({left, a - 1});
                root = add1(root, {left, a - 1});
                s.insert({a, right});
                root = add1(root, {a, right});
            }
            else
            {
                s.insert({left, a - 1});
                root = add1(root, {left, a - 1});
                s.insert({a + 1, right});
                root = add1(root, {a + 1, right});
                s.insert({a, a});
                root = add1(root, {a, a});
            }
            mass[a] = b;
        }
    }
}