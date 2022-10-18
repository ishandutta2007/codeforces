#include <bits/stdc++.h>
using namespace std;


struct Line {
    long long k, d;

    long long eval(int x) {
        return k * x + d;
    }
};

class LiChaoTree {
public:
    LiChaoTree(int n) : n(n) {
        inf = {0LL, std::numeric_limits<long long>::max() / 2};
        lines.resize(4 * n);
        reset();
    }

    void reset() {
        fill(lines.begin(), lines.end(), inf);
    }

    void add_line(Line new_line, int id=1, int l=0, int r=-1) {
        if (r == -1)
            r = n;

        int m = (l + r) / 2;
        bool left = new_line.eval(l) < lines[id].eval(l);
        bool middle = new_line.eval(m) < lines[id].eval(m);
        if (middle)
            std::swap(lines[id], new_line);

        if (r - l == 1)
            return;

        if (left != middle)
            add_line(new_line, id << 1, l, m);
        else
            add_line(new_line, id << 1 | 1, m, r);
    }

    long long get_minimum(int x, int id=1, int l=0, int r=-1) {
        if (r == -1)
            r = n;

        long long seg_value = lines[id].eval(x);
        if (r - l == 1)
            return seg_value;

        int m = (l + r) / 2;
        if (x < m)
            return std::min(seg_value, get_minimum(x, id << 1, l, m));
        else 
            return std::min(seg_value, get_minimum(x, id << 1 | 1, m, r));
    }

    int n;
    std::vector<Line> lines;
    Line inf;
};

struct Server
{
    long long c;
    int index;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x1, x2;
    cin >> n >> x1 >> x2;
    vector<Server> servers(n);
    for (int i = 0; i < n; i++) {
        cin >> servers[i].c;
        servers[i].index = i + 1;
    }

    sort(servers.begin(), servers.end(), [](auto p, auto q) {
        return p.c < q.c;
    });

    LiChaoTree lichao(n + 1);

    // try x1 x2;
    for (int i = 0; i < n; i++) {
        long long sum = servers[i].c * (n - i);
        if (sum >= x2) {
            if (-lichao.get_minimum(i) >= x1) {
                cout << "Yes" << '\n';
                // cout << i << '\n';
                // cout << -lichao.get_minimum(i) << '\n';
                
                int j;
                for (j = 0; j < n; j++) {
                    if (servers[j].c * (i - j) >= x1) {
                        break;
                    }
                }

                cout << (i - j) << " " << (n - i) << "\n";
                for (int k = j; k < i; k++) {
                    cout << servers[k].index << " ";
                }
                cout << '\n';
                for (int k = i; k < n; k++) {
                    cout << servers[k].index << " ";
                }
                cout << '\n';

                
                return 0;
            }
        }
        if (sum >= x1) {
            if (-lichao.get_minimum(i) >= x2) {
                cout << "Yes" << '\n';
                int j;
                for (j = 0; j < n; j++) {
                    if (servers[j].c * (i - j) >= x2) {
                        break;
                    }
                }
                cout << (n - i) << " " << (i - j) << "\n";
                for (int k = i; k < n; k++) {
                    cout << servers[k].index << " ";
                }
                cout << '\n';
                for (int k = j; k < i; k++) {
                    cout << servers[k].index << " ";
                }
                cout << '\n';
                return 0;
            }
        }
        lichao.add_line(Line{-servers[i].c, servers[i].c*i});
    }

    cout << "No" << '\n';
}