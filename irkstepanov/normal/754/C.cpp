#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const int inf = 1e9;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("triangles.out");

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    string tmp;

    while (tt--) {
        int n;
        cin >> n;
        vector<string> names;
        map<string, int> num;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            names.pb(s);
            num[s] = i;
        }
        int q;
        cin >> q;
        vector<string> author(q), text(q);
        getline(cin, tmp);
        for (int i = 0; i < q; ++i) {
            string s;
            getline(cin, s);
            int pos = -1;
            for (int i = 0; i < sz(s); ++i) {
                if (s[i] == ':') {
                    pos = i;
                    break;
                }
            }
            author[i] = s.substr(0, pos);
            text[i] = s.substr(pos + 1, sz(s) - pos - 1);
        }
        vector<set<string> > used(q);
        for (int i = 0; i < q; ++i) {
            string curr = "";
            for (int j = 0; j <= sz(text[i]); ++j) {
                if (j == sz(text[i]) || (!isalpha(text[i][j]) && !isdigit(text[i][j]))) {
                    if (curr != "") {
                        used[i].insert(curr);
                    }
                    curr = "";
                } else {
                    curr += text[i][j];
                }
            }
        }
        vector<vector<int> > p(n, vector<int>(q, inf));
        if (author[0] == "?") {
            for (int i = 0; i < n; ++i) {
                if (!used[0].count(names[i])) {
                    p[i][0] = -1;
                }
            }
        } else {
            p[num[author[0]]][0] = -1;
        }
        for (int j = 1; j < q; ++j) {
            if (author[j] == "?") {
                for (int i = 0; i < n; ++i) {
                    if (used[j].count(names[i])) {
                        continue;
                    }
                    for (int prev = 0; prev < n; ++prev) {
                        if (prev == i) {
                            continue;
                        }
                        if (p[prev][j - 1] == inf) {
                            continue;
                        }
                        p[i][j] = prev;
                    }
                }
            } else {
                int id = num[author[j]];
                for (int prev = 0; prev < n; ++prev) {
                    if (prev == id) {
                        continue;
                    }
                    if (p[prev][j - 1] == inf) {
                        continue;
                    }
                    p[id][j] = prev;
                }
            }
        }
        int curr = -1;
        for (int i = 0; i < n; ++i) {
            if (p[i][q - 1] != inf) {
                curr = i;
            }
        }
        if (curr == -1) {
            cout << "Impossible\n";
        } else {
            vector<int> id(q);
            id[q - 1] = curr;
            for (int j = q - 1; j > 0; --j) {
                curr = p[curr][j];
                id[j - 1] = curr;
            }
            for (int j = 0; j < q; ++j) {
                cout << names[id[j]] << ":" << text[j] << "\n";
            }
        }
    }

}