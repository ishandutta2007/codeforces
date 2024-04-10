#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef long long ll;
typedef long double ld;

struct node
{
    bool term;
    node* to[3];
    node()
    {
        term = false;
        to[0] = to[1] = to[2] = nullptr;
    }
};

node* root = new node();

void add(const string& s)
{
    node* curr = root;
    for (int i = 0; i < sz(s); ++i) {
        if (curr->to[s[i] - 'a'] == nullptr) {
            curr->to[s[i] - 'a'] = new node();
        }
        curr = curr->to[s[i] - 'a'];
    }
    curr->term = true;
}

bool get(node* curr, const string& s, int pos, int mis)
{
    if (pos == sz(s) && curr->term) {
        return mis;
    } else if (pos == sz(s)) {
        return false;
    }
    if (!mis) {
        for (int i = 0; i < 3; ++i) {
            if (curr->to[i] != nullptr) {
                if (get(curr->to[i], s, pos + 1, i != s[pos] - 'a')) {
                    return true;
                }
            }
        }
        return false;
    }
    if (curr->to[s[pos] - 'a'] != nullptr) {
        return get(curr->to[s[pos] - 'a'], s, pos + 1, 1);
    }
    return false;
}

int main()
{

    //ifstream cin("input.txt");

    int n, q;
    cin >> n >> q;

    while (n--) {
        string s;
        cin >> s;
        add(s);
    }

    while (q--) {
        string s;
        cin >> s;
        cout << (get(root, s, 0, 0) ? "YES\n" : "NO\n");
    }

}