// Hydro submission #6201dc9ac3e66c133127a7ee@1644289178803
#include<bits/stdc++.h>
#include<bits/extc++.h>

using namespace std;

vector<vector<int>> seq, se[2][2];
vector<int> ed[2], ans;
int n, tot;
string s;

void PB(vector<int> &x, const vector<int> &y) {
    x.insert(x.end(), y.begin(), y.end());
}

void PF(vector<int> &x, const vector<int> &y) {
    x.insert(x.begin(), y.begin(), y.end());
}

int main() {
    cin >> s, n = s.size(), s = ' ' + s;

    for (int i = 1; i <= n; i++) {
        int x = s[i] == 'R';
        if (ed[x ^ 1].empty())
            seq.emplace_back(vector<int>(1, i)), ed[x].emplace_back(tot++);
        else {
            int y = ed[x ^ 1].back();
            seq[y].emplace_back(i), ed[x].emplace_back(y), ed[x ^ 1].pop_back();
        }
    }

    printf("%d\n", tot - 1);

    for (auto x : seq)
        se[s[x.front()] == 'R'][s[x.back()] == 'R'].emplace_back(x);

    for (int i = 1, s = se[0][1].size(); i < s; i++)
        PB(se[0][1][0], se[0][1][i]);

    for (int i = 1, s = se[1][0].size(); i < s; i++)
        PB(se[1][0][0], se[1][0][i]);

    if (!se[0][0].empty() || !se[1][1].empty()) {
        if (!se[0][0].empty()) {
            if (!se[0][1].empty())
                PF(se[0][0][0], se[0][1][0]);

            if (!se[1][0].empty())
                PB(se[0][0][0], se[1][0][0]);
        } else {
            if (!se[0][1].empty())
                PB(se[1][1][0], se[0][1][0]);

            if (!se[1][0].empty())
                PF(se[1][1][0], se[1][0][0]);
        }

        if (se[0][0].size() < se[1][1].size())
            swap(se[0][0], se[1][1]);

        for (int i = 0, j = 0, s0 = se[0][0].size(), s1 = se[1][1].size(); i < s0 || j < s1;) {
            PB(ans, se[0][0][i++]);

            if (j < s1)
                PB(ans, se[1][1][j++]);
        }
    } else if (se[0][1].empty() || se[1][0].empty()) {
        if (se[0][1].empty())
            ans = se[1][0][0];
        else
            ans = se[0][1][0];
    } else {
        if (se[0][1][0].back() < se[1][0][0].back()) {
            se[0][1][0].emplace_back(se[1][0][0].back()), se[1][0][0].pop_back();
            PB(se[0][1][0], se[1][0][0]), ans = se[0][1][0];
        } else {
            se[1][0][0].emplace_back(se[0][1][0].back()), se[0][1][0].pop_back();
            PB(se[1][0][0], se[0][1][0]), ans = se[1][0][0];
        }
    }

    for (int x : ans)
        printf("%d ", x);
    puts("");

    return 0;
}