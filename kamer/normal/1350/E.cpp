#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
typedef long long ll;
bool a[1000][1000];
int b[1000][1000];
bool handled[1000][1000];
bool dijkstra[1000][1000];

class DijkstraComparator {

public:
    bool operator() (tuple<int, int, int> lhs, tuple<int, int, int> rhs) {
        return get<2>(lhs) > get<2>(rhs);
    }
};

vector<tuple<int, int>> simpleNeighbours(int i, int j) {
    vector<tuple<int, int>> result;
    result.push_back(make_tuple(i, j - 1));
    result.push_back(make_tuple(i, j + 1));
    result.push_back(make_tuple(i - 1, j));
    result.push_back(make_tuple(i + 1, j));
    return result;

}

vector<tuple<int, int>> findNeighbours(int i, int j, int n, int m) {
    vector<tuple<int, int>> result;
    for (auto neigh : simpleNeighbours(i, j)) {    
        int x = get<0>(neigh), y = get<1>(neigh);
        if (x >= 0 && x < n && y >= 0 && y < m) {
            if (a[i][j] == a[x][y]) {
                result.push_back(make_tuple(x, y));
            }
        }
    }
    return result;
}

vector<tuple<int, int>> search(int i, int j, int n, int m) {
    vector<tuple<int, int>> result;
    if (handled[i][j]) return result;
    result.push_back(make_tuple(i, j));
    handled[i][j] = true;
    vector<tuple<int, int>> neighbours = findNeighbours(i, j, n, m);
    for (auto neighbour : neighbours) {
        auto neighs = search(get<0>(neighbour), get<1>(neighbour), n, m);
        result.insert(result.end(), neighs.begin(), neighs.end());
    }
    return result;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, t;
    cin >> n >> m >> t;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            b[i][j] = 0;
            handled[i][j] = false;
            dijkstra[i][j] = false;
            char c;
            cin >> c;
            if (c == '0') a[i][j] = false;
            else          a[i][j] = true;
        }
    }

    // find components
    vector<vector<tuple<int, int>>> components;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            auto comp = search(i, j, n, m);
            if (comp.size() > 1) {
                components.push_back(comp);
            }
        }
    }
    if (components.empty()) {
        while (t--) {
            ll i, j, p;
            cin >> i >> j >> p;
            i--, j--;
            if (a[i][j]) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        }
    } else {

        // now do some form of dijkstra
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, DijkstraComparator> dijkstraQueue;
        for (auto component : components) {
            for (auto elem : component) {
                dijkstraQueue.push(make_tuple(get<0>(elem), get<1>(elem), 0));
            }
        }
        
        while (!dijkstraQueue.empty()) {
            auto elem = dijkstraQueue.top();
            dijkstraQueue.pop();
            int i = get<0>(elem), j = get<1>(elem), l = get<2>(elem);
            if (!dijkstra[i][j]) {
                b[i][j] = l;
                dijkstra[i][j] = true;
                for (auto neigh : simpleNeighbours(i, j)) {
                    int x = get<0>(neigh), y = get<1>(neigh);
                    if (x >= 0 && x < n && y >= 0 && y < m) {
                        dijkstraQueue.push(make_tuple(x, y, l + 1));
                    }
                }
            }
        }

        while (t--) {
            ll i, j, p;
            cin >> i >> j >> p;
            i--, j--;
            if (p <= (ll) b[i][j]) {
                if (a[i][j]) {
                    cout << "1\n";
                } else {
                    cout << "0\n";
                }
            } else {
                bool even = (((p - b[i][j]) % 2) == 0);
                if (even == a[i][j]) {
                    cout << "1\n";
                } else {
                    cout << "0\n";
                }
            }
        }
    }
    return 0;
}