#include <bits/stdc++.h>

#define sz(a) static_cast<int>(a.size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

struct node
{
    node* to[26];
    int s;
    node()
    {
        for (int i = 0; i < 26; ++i) {
            to[i] = nullptr;
        }
        s = -1;
    }
};

node *root = new node();

const int nmax = 10000;
const int mmax = 1000;

int main()
{

    //ifstream cin("input.txt");

    ios::sync_with_stdio(false);
    int n;
    //scanf("%d", &n);
    cin >> n;
    //char s[nmax];
    //scanf("%s", s);
    string s;
    cin >> s;

    int q;
    cin >> q;
    vector<string> input(q);
    for (int i = 0; i < q; ++i) {
        cin >> input[i];
        string trans = input[i];
        for (int j = 0; j < sz(input[i]); ++j) {
            if (trans[j] >= 'A' && trans[j] <= 'Z') {
                trans[j] = (char)(trans[j] - 'A' + 'a');
            }
        }
        node *curr = root;
        for (int j = 0; j < sz(input[i]); ++j) {
            if (curr->to[trans[j] - 'a'] != nullptr) {
                curr = curr->to[trans[j] - 'a'];
            } else {
                node *tmp = new node();
                curr->to[trans[j] - 'a'] = tmp;
                curr = tmp;
            }
        }
        if (curr->s == -1) {
            curr->s = i;
        }
    }

    vector<int> dp(n, -1);

    for (int i = 0; i < n; ++i) {
        node *curr = root;
        for (int j = i; j >= 0; --j) {
            if (curr->to[s[j] - 'a'] != nullptr) {
                curr = curr->to[s[j] - 'a'];
            } else {
                break;
            }
            if (curr->s != -1 && (j == 0 || dp[j - 1] != -1)) {
                dp[i] = curr->s;
                break;
            }
        }
    }

    int pos = n - 1;
    vector<int> ans;

    while (pos >= 0) {
        ans.pb(dp[pos]);
        pos -= sz(input[ans.back()]);
    }

    for (int i = sz(ans) - 1; i >= 0; --i) {
        cout << input[ans[i]];
        if (i) {
            cout << " ";
        }
    }
    cout << "\n";

}