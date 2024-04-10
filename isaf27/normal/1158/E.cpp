#include <bits/stdc++.h>

using namespace std;

const int M = 1010;

vector<bool> ask(vector<int> d)
{
    cout << "? ";
    for (int i : d)
        cout << i << " ";
    cout << endl;
    string s;
    cin >> s;
    vector<bool> ans((int)d.size());
    for (int i = 0; i < (int)d.size(); i++)
        ans[i] = (bool)(s[i] - '0');
    return ans;
}

int n;
vector<int> in[M], nxt[M];
vector<int> pos;
bool used[M];
int pr[M];

int main()
{
    cin >> n;
    in[0].push_back(0);
    for (int i = 1; i < n; i++)
        nxt[0].push_back(i);
    used[0] = true;
    used[n] = true;
    while (true)
    {
        bool stop = true;
        pos.clear();
        for (int i = 0; i <= n; i++)
            if (used[i])
                pos.push_back(i);
        for (int st = 0; st < 2; st++)
        {
            vector<int> r1(n, 0), r2(n, 0);
            for (int s = st; s < (int) pos.size() - 1; s += 2)
            {
                if (in[pos[s]].empty()) continue;
                if (pos[s + 1] == pos[s] + 1) continue;
                if (pos[s + 1] == pos[s] + 2)
                {
                    in[pos[s] + 1] = nxt[pos[s]];
                    nxt[pos[s]].clear();
                    used[pos[s] + 1] = true;
                    continue;
                }
                stop = false;
                int mid = (pos[s] + pos[s + 1] + 1) >> 1;
                for (int x : in[pos[s]])
                {
                    r1[x] = mid - pos[s] - 1;
                    r2[x] = r1[x] + 1;
                }
            }
            vector<bool> a1 = ask(r1);
            vector<bool> a2 = ask(r2);
            for (int s = st; s < (int) pos.size() - 1; s += 2)
            {
                if (in[pos[s]].empty()) continue;
                if (pos[s + 1] <= pos[s] + 2) continue;
                int mid = (pos[s] + pos[s + 1] + 1) >> 1;
                vector<int> now = nxt[pos[s]];
                nxt[pos[s]].clear();
                for (int x : now)
                {
                    if (a1[x])
                        nxt[pos[s]].push_back(x);
                    else if (a2[x])
                        in[mid].push_back(x);
                    else
                        nxt[mid].push_back(x);
                }
                used[mid] = true;
            }
        }
        if (stop)
            break;
    }
    for (int st = 1; st <= 3; st++)
    {
        for (int i = 0; (1 << i) < n; i++)
        {
            vector<int> r(n, 0);
            bool need = false;
            for (int x = st; x < n; x += 3)
                if (!in[x].empty())
                    for (int t : in[x - 1])
                        if ((t >> i) & 1)
                        {
                            r[t] = 1;
                            need = true;
                        }
            if (!need) continue;
            vector<bool> res = ask(r);
            for (int x = st; x < n; x += 3)
                if (!in[x].empty())
                    for (int t : in[x])
                        if (res[t])
                            pr[t] ^= (1 << i);
        }
    }
    cout << "!" << endl;
    for (int i = 1; i < n; i++)
        cout << pr[i] + 1 << " " << i + 1 << endl;
    return 0;
}