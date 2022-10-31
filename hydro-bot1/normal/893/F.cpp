// Hydro submission #62c5655dc3a9fda562296d05@1657103709702
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node;

int N, Q, R;
vector<int> adjlist[100001];
vector<int> layers[100001];
int arr[100001];
int in[100001];
int out[100001];
int vis[100001];
int depth[100001];
Node* pst[200001];

struct Node
{
    int v;
    Node* l;
    Node* r;

    Node(int a) {v = a, l = r = nullptr;}
    Node(Node* left, Node* right)
    {
        v = min(left->v, right->v);
        l = left;
        r = right;
    }
};

Node* build(int ss, int se)
{
    if (ss == se) return new Node(1e9);
    int mid = (ss + se) / 2;
    return new Node(build(ss, mid), build(mid + 1, se));
}

Node* update(Node* n, int a, int v, int ss, int se)
{
    if (ss == se) return new Node(v);

    int mid = (ss + se) / 2;
    if (a <= mid) return new Node(update(n->l, a, v, ss, mid), n->r);
    else return new Node(n->l, update(n->r, a, v, mid + 1, se));
}

int query(Node* n, int a, int b, int ss, int se)
{
    if (a <= ss && se <= b) return n->v;

    int mid = (ss + se) / 2;
    int ans = 2e9;
    if (a <= mid) ans = min(ans, query(n->l, a, b, ss, mid));
    if (b > mid) ans = min(ans, query(n->r, a, b, mid + 1, se));
    return ans;
}

int cnt = 0;
int d = 0;
int maxd = 0;
void DFS(int a)
{
    cnt++;
    d++;
    in[a] = cnt;
    maxd = max(d, maxd);
    layers[d].push_back(a);
    depth[a] = d;
    vis[a] = 1;
    for (int i = 0; i < adjlist[a].size(); i++)
    {
        int tar = adjlist[a][i];
        if (!vis[tar]) DFS(tar);
    }
    out[a] = cnt;
    d--;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> R;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    for (int i = 1; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }

    DFS(R);
    pst[0] = build(1, cnt);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < layers[i].size(); j++)
        {
            int tar = layers[i][j];
            if (j == 0) pst[i] = update(pst[i - 1], in[tar], arr[tar], 1, cnt);
            else pst[i] = update(pst[i], in[tar], arr[tar], 1, cnt);
        }
    }
    
    cin >> Q;
    int lastans = 0;
    for (int i = 1; i <= Q; i++)
    {
        int x, k, p, q;
        cin >> p >> q;
        x = (p + lastans) % N + 1;
        k = (q + lastans) % N;
        int chosen = min(depth[x] + k, maxd);
        lastans = query(pst[chosen], in[x], out[x], 1, cnt);
        cout << lastans << endl;
    }
    return 0;
}