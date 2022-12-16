#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int n;
int root;
vector<int> adj[300000];

int maxdepth = 0;
int onething = -1;
int twothing = -1;

bool visited1[300000];
bool visited2[300000];
bool visited3[300000];
bool visited4[300000];

int distfromone[300000];
int distfromtwo[300000];

void dfs1(int start, int depth) {
    visited1[start] = true;
    if (depth > maxdepth) {
        maxdepth = depth;
        onething = start;
    }

    for (int conn : adj[start]) {
        if (visited1[conn]) continue;
        dfs1(conn, depth+1);
    }
}

void dfs2(int start, int depth) {
    visited2[start] = true;
    if (depth > maxdepth) {
        maxdepth = depth;
        twothing = start;
    }

    for (int conn : adj[start]) {
        if (visited2[conn]) continue;
        dfs2(conn, depth+1);
    }
}

void dfs3(int start, int depth) {
    distfromone[start] = depth;
    visited3[start] = true;

    for (int conn : adj[start]) {
        if (visited3[conn]) continue;
        dfs3(conn, depth+1);
    }
}

void dfs4(int start, int depth) {
    distfromtwo[start] = depth;
    visited4[start] = true;

    for (int conn : adj[start]) {
        if (visited4[conn]) continue;
        dfs4(conn, depth+1);
    }
}

unordered_set<int> seen;
bool trvisited[300000];

bool trdfs(int start, int target) {
    //cout << start << ' ' << target << endl;
    if (trvisited[start]) return false;
    //cout << "here" << endl;
    trvisited[start] = true;
    if (start == target) {
        seen.insert(start);
        return true;
    }
    //cout << "here2" << endl;
    for (int conn : adj[start]) {
        //cout << conn << endl;
        if (trvisited[conn]) continue;
        if (trdfs(conn, target)) {
            //cout << "what" << endl;
            seen.insert(start);
            return true;
        } else {
            //cout << conn << " not in path of " << target << endl;
        }
    }
    return false;
}

int tr(int x, int y, int z) {
    for (int i = 0; i < n; i++) {
        trvisited[i] = false;
    }
    seen.clear();
    trdfs(x, y);
    for (int i = 0; i < n; i++) {
        trvisited[i] = false;
    }
    trdfs(x, z);
    return seen.size() - 1;
}

int main() {
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (n <= 0) {
        int best = 0;
        int chosen[3];
        //cout << tr(1, 5, 6) << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                for (int k = 2; k < n; k++) {
                    int outcome = tr(i, j, k);
                    //cout << outcome << endl;
                    if (outcome > best) {
                        best = outcome;
                        chosen[0] = i;
                        chosen[1] = j;
                        chosen[2] = k;
                    }
                }
            }
        }
        cout << best << endl;
        cout << chosen[0] << ' ' << chosen[1] << ' ' << chosen[2] << endl;
    } else {
    
    root = -1;
    int maxadj = 1;
    for (int i = 0; i <= n; i++) {
        if (adj[i].size() > maxadj) {
            root = i;
            maxadj = adj[i].size();
        }
    }

    dfs1(root, 1);
    //cout << root << ' ' << onething << endl;
    maxdepth = 0;
    dfs2(onething, 1);
    //cout << twothing << endl;
    dfs3(onething, 0);
    dfs4(twothing, 0);

    int out = 0;
    int chosenthree = -1;

    for (int i = 0; i <= n; i++) {
        int winning = distfromone[i] + distfromtwo[i];
        if (winning > out && i != onething && i != twothing) {
            out = winning;
            chosenthree = i;
        }
    }
    for (int i = 0; i <= n; i++) {
        trvisited[i] = false;
    }
    trdfs(onething, twothing);
    //cout << seen.size() << endl;
    for (int i = 0; i <= n; i++) {
        trvisited[i] = false;
    }
    trdfs(twothing, chosenthree);
    //if (maxdepth == distfromone[chosenthree] + distfromtwo[chosenthree]) out++;
    cout << seen.size()-1 << endl;
    cout << onething << ' ' << twothing << ' ' << chosenthree << endl;
    }
}