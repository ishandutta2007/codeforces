#include <bits/stdc++.h>
using namespace std;

struct pt {
    int x, y;
    pt() : x(0), y(0)
    {}

    pt (int _y, int _x) : x(_x), y(_y)
    {}

    bool operator < (const pt other) const {
        return x < other.x || (x == other.x && y == other.y);
    }
};

int h, w;
vector<vector<char> > field;

set<pt> visited;
map<pt, vector<pt>> g;
vector<vector<bool> > used;


void print(pt p) {
    cerr << "(y:" << p.y << ", x:" << p.x << ")";
}

void dfs(pt p) {
    if (used[p.y][p.x]) return;
    print(p);
    cerr << endl;

    used[p.y][p.x] = true;
    visited.insert(p);

    for (auto to: g[p]) {
        dfs(to);
    }
}

int main() {
  cin >> h >> w;
  field.resize(h, vector<char>(w));

  for (int y = 0; y < h;  ++y) {
    for (int x = 0; x < w; ++x) {
        cin >> field[y][x];
    }
  }

  vector<vector<set<int>>> byy(h, vector<set<int>>(w));
  vector<vector<set<int>>> byx(h, vector<set<int>>(w));

  for (int y = 0; y < h; ++y) {
    for (int x = 0; x < w; ++x) {
        if (field[y][x] == '#') {
            for (int y1 = 0; y1 < h; ++y1) {
                if (field[y1][x] == '#') {
                    byy[y][x].insert(y1);
                }
            }
            for (int x1 = 0; x1 < w; ++x1) {
                if (field[y][x1] == '#') {
                    byx[y][x].insert(x1);
                }
            }
        }
    }
  }

  for (int y = 0; y < h; ++y) {
    for (int x = 0; x < w; ++x) {
        if (field[y][x] == '#') {
            for (int y1 = 0; y1 < h; ++y1) {
                if (field[y1][x] == '#') {
                    if (byx[y][x] != byx[y1][x]) {
                        cout << "No" << endl;
                        return 0;
                    }
                }
            }

            for (int x1 = 0; x1 < w; ++x1) {
                if (field[y][x1] == '#') {
                    if (byy[y][x] != byy[y][x1]) {
                        cout << "No" << endl;
                        return 0;
                    }
                }
            }
        }
    }
  }

  cout << "Yes" << endl;
  return 0;
}