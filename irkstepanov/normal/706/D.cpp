#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, int> pll;

const int rmax = 30;

bool bit(int mask, int pos)
{
    return (mask >> pos) & 1;
}

struct node
{
    node* left;
    node* right;
    int cnt;
    node() : left(0), right(0), cnt(0) {}
};

node* root = new node();

void add(int val)
{
    node* curr = root;
    ++curr->cnt;
    for (int r = rmax - 1; r >= 0; --r) {
        if (!bit(val, r)) {
            if (curr->left != nullptr) {
                curr = curr->left;
                ++curr->cnt;
            } else {
                node* son = new node();
                son->cnt = 1;
                curr->left = son;
                curr = son;
            }
        } else {
            if (curr->right != nullptr) {
                curr = curr->right;
                ++curr->cnt;
            } else {
                node* son = new node();
                son->cnt = 1;
                curr->right = son;
                curr = son;
            }
        }
    }
}

void del(int val)
{
    node* curr = root;
    --curr->cnt;
    for (int r = rmax - 1; r >= 0; --r) {
        if (!bit(val, r)) {
            curr = curr->left;
            --curr->cnt;
        } else {
            curr = curr->right;
            --curr->cnt;
        }
    }
}

int get(int val)
{
    int ans = 0;
    node* curr = root;
    for (int r = rmax - 1; r >= 0; --r) {
        if (bit(val, r)) {
            if (curr->left != nullptr && curr->left->cnt) {
                ans |= (1 << r);
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        } else {
            if (curr->right != nullptr && curr->right->cnt) {
                ans |= (1 << r);
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }
    }
    return ans;
}

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    root->cnt = 1;
    node* curr = root;
    for (int r = rmax - 1; r >= 0; --r) {
        node* son = new node();
        son->cnt = 1;
        curr->left = son;
        curr = son;
    }

    int q;
    scanf("%d\n", &q);
    while (q--) {
        char type;
        scanf("%c", &type);
        int x;
        scanf("%d\n", &x);
        if (type == '+') {
            add(x);
        } else if (type == '-') {
            del(x);
        } else {
            printf("%d\n", get(x));
        }
    }

}