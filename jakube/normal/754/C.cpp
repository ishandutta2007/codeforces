#include <bits/stdc++.h>
using namespace std;

struct Message
{
    int person = -1;
    vector<bool> v;
    int cnt = 0;
    bool add(int x) {
        if (!v[x]) {
            return false;
        } else {
            cnt--;
            v[x] = false;
            return true;
        }
    }
    string msg;
};


vector<string> parseMsg(string msg) {
    msg += '.';
    string s;
    vector<string> v;
    for (char c : msg) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            s += c;
        } else {
            if (!s.empty())
                v.push_back(s);
            s.clear();
        }
    }
    return v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t --> 0) {
        int n;
        cin >> n;
        vector<string> names(n);
        map<string, int> ma;
        for (int i = 0; i < n; i++) {
            cin >> names[i];
            ma[names[i]] = i;
        }

        int m;
        cin >> m;
        string s;
        getline(cin, s);
        vector<Message> messages(m);
        for (int i = 0; i < m; i++) {
            string s;
            getline(cin, s);
            int idx = s.find(':');
            string name = s.substr(0, idx);
            messages[i].msg = s.substr(idx);
            auto msg = parseMsg(s.substr(idx+1));
            if (name != "?") {
                messages[i].person = ma[name];
                messages[i].cnt = 1;
                messages[i].v.assign(n, false);
                messages[i].v[ma[name]] = true;
            } else {
                messages[i].v.assign(n, true);
                messages[i].cnt = n;
                for (auto w : msg) {
                    if (ma.count(w))
                        messages[i].add(ma[w]);
                }
            }
        }

        for (int i = 0; i < m; i++) {
            if (i && messages[i-1].person >= 0) {
                messages[i].add(messages[i-1].person);
            }
            if (i + 1 < m && messages[i+1].person >= 0) {
                messages[i].add(messages[i+1].person);
            }
        }

        queue<int> q;
        for (int i = 0; i < m; i++) {
            auto & msg = messages[i];
            if (msg.person < 0 && msg.cnt == 1)
                q.push(i);
        }

        while (!q.empty()) {
            auto x = q.front();
            auto & msg = messages[x];
            q.pop();

            int idx;
            for (int i = 0; i < n; i++) {
                if (msg.v[i])
                    idx = i;
            }
            msg.person = idx;
            if (x && messages[x-1].add(idx)) {
                if (messages[x-1].cnt == 1)
                    q.push(x-1);
            }
            if (x+1<m && messages[x+1].add(idx)) {
                if (messages[x+1].cnt == 1)
                    q.push(x+1);
            }
        }

        bool possible = true;
        for (int i = 0; i < m; i++) {
            auto & msg = messages[i];
            if (msg.person < 0) {
                if (msg.cnt == 0)
                    possible = false;
                else {
                    int idx;
                    for (int i = 0; i < n; i++) {
                        if (msg.v[i])
                            idx = i;
                    }
                    msg.person = idx;
                    if (i + 1 < m)
                        messages[i+1].add(idx);
                }
            }
        }

        if (possible) {
            for (auto msg : messages) {
                cout << names[msg.person] << msg.msg << '\n';
            }
        } else {
            cout << "Impossible" << '\n';
        }
    }
}