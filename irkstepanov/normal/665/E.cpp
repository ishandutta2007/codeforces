#include <iostream>
#include <map>
#include <vector>
#include <fstream>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int bits = 31;

bool bit(int mask, int pos)
{
    return (mask >> pos) & 1;
}

struct node
{
    int size;
    node* l;
    node* r;
    node() : size(0), l(nullptr), r(nullptr) {}
};

node* root = new node();

void add(node* v, int val)
{
    node* curr = v;
    for (int b = bits; b >= -1; --b) {
        ++curr->size;
        if (b == -1) {
            break;
        }
        if (bit(val, b)) {
            if (curr->r == nullptr) {
                curr->r = new node();
            }
            curr = curr->r;
        } else {
            if (curr->l == nullptr) {
                curr->l = new node();
            }
            curr = curr->l;
        }
    }
}

int get(node* v, int val, int k)
{
    node* curr = v;
    int ans = 0;
    for (int b = bits; b >= -1; --b) {
        if (b == -1) {
            ans += curr->size;
            break;
        }
        if (bit(k, b)) {
            if (bit(val, b)) {
                if (curr->l == nullptr) {
                    break;
                } else {
                    curr = curr->l;
                }
            } else {
                if (curr->r == nullptr) {
                    break;
                } else {
                    curr = curr->r;
                }
            }
        } else {
            if (bit(val, b)) {
                if (curr->l != nullptr) {
                    ans += curr->l->size;
                }
                if (curr->r != nullptr) {
                    curr = curr->r;
                } else {
                    break;
                }
            } else {
                if (curr->r != nullptr) {
                ans += curr->r->size;
                }
                if (curr->l != nullptr) {
                    curr = curr->l;
                } else {
                    break;
                }
            }
        }
    }
    return ans;
}

int main()
{

    //ifstream cin("input.txt");

    int n, k;
    scanf("%d%d", &n, &k);

    ll ans = 0;
    int pref = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        pref ^= a;
        add(root, pref);
        if (pref >= k) {
            ++ans;
        }
        ans += get(root, pref, k);
    }

    printf("%I64d\n", ans);

}