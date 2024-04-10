#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

const int rmax = 30;

bool bit(int mask, int pos)
{
    return (mask >> pos) & 1;
}

struct node
{
    int cnt;
    node* left;
    node* right;
    node() : cnt(0), left(nullptr), right(nullptr) {}
};

node* root = new node();

void upd(int x, int type)
{
    node* curr = root;
    for (int r = rmax - 1; r >= 0; --r) {
        if (type == 1) {
            ++curr->cnt;
        } else {
            --curr->cnt;
        }
        if (!bit(x, r)) {
            if (curr->left == nullptr) {
                curr->left = new node();
            }
            curr = curr->left;
        } else {
            if (curr->right == nullptr) {
                curr->right = new node();
            }
            curr = curr->right;
        }
    }
    if (type == 1) {
        ++curr->cnt;
    } else {
        --curr->cnt;
    }
}

int getCnt(node* v)
{
    return (v == nullptr ? 0 : v->cnt);
}

int get(int x, int l)
{
    node* curr = root;
    int ans = 0;
    for (int r = rmax - 1; r >= 0; --r) {
        int b = bit(x, r);
        if (b < bit(l, r)) {
            ans += getCnt(curr->left);
        }
        if ((b ^ 1) < bit(l, r)) {
            ans += getCnt(curr->right);
        }
        if (b == bit(l, r) && curr->left != nullptr) {
            curr = curr->left;
        } else if ((b ^ 1) == bit(l, r) && curr->right != nullptr) {
            curr = curr->right;
        } else {
            break;
        }
    }
    return ans;
}

int main()
{

    //ifstream cin("input.txt");
	//ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;

    while (q--) {
        int type;
        cin >> type;
        if (type != 3) {
            int x;
            cin >> x;
            upd(x, type);
        } else {
            int x, l;
            cin >> x >> l;
            cout << get(x, l) << "\n";
        }
    }

}