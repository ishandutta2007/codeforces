const long long INFLL = 1e18;
const long long MOD = 998244353;

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define forn(i, n) for (int i = 0; (i) != (n); (i)++)
#define all(v) (v).begin(), (v).end()
#define uniq(x) sort(all(x)); x.resize(unique(all(x)) - (x).begin())

ll MAXC = 0;

long double sqr(long double x)
{
    return x * x;
}

void solve()
{
    int n;
    cin >> n;

    struct Point{
        ll x, y, z;
        int id;
    };

    vector<Point> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].x >> p[i].y >> p[i].z;
        MAXC = max(MAXC, p[i].z);
        p[i].id = i;
    }
    sort(all(p), [&](Point a, Point b){
         return a.z > b.z;
         });

    vector<int> newid(n);
    for (int i = 0; i < n; i++)
    {
        newid[p[i].id] = i;
    }

    int m;
    cin >> m;
    vector<vector<int> > faces(m, vector<int>(3));
    vector<vector<int> > in_faces(n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> faces[i][j];
            faces[i][j]--;
            faces[i][j] = newid[faces[i][j]];
            in_faces[faces[i][j]].push_back(i);
        }
        sort(all(faces[i]), [&](int i, int j){
             return p[i].z > p[j].z;
             });
    }

    int q;
    cin >> q;

    struct Query{
        int h, p;
        int id;
        long double answer;
    };

    vector<Query> asks(q);
    for (int i = 0; i < q; i++)
    {
        cin >> asks[i].h >> asks[i].p;
        asks[i].p--;
        asks[i].p = newid[asks[i].p];
        asks[i].id = i;
    }

    sort(all(asks), [&](Query a, Query b){
         return a.h > b.h;
         });

    // solution

    auto dist = [&](Point A, Point B)
    {
        return sqrt(sqr(A.x - B.x) + sqr(A.y - B.y) + sqr(A.z - B.z));
    };

    auto dot_product = [&](Point A, Point B, Point O)
    {
        return (A.x - O.x) * (B.x - O.x) + (A.y - O.y) * (B.y - O.y) + (A.z - O.z) * (B.z - O.z);
    };

    auto cos = [&](Point A, Point B, Point O)
    {
        return dot_product(A, B, O) / dist(A, O) / dist(B, O);
    };

    auto sin = [&](Point A, Point B, Point O)
    {
        return sqrt(1 - sqr(cos(A, B, O)));
    };

    // data for triangles
    vector<int> points_on_face(m);
    vector<long double> parts(m);
    vector<long double> computed_area(m);
    vector<long double> lin_func(m);
    vector<long double> K(m);

    struct dsu{
        vector<int> root;
        vector<int> sz;
        vector<long double> parts;
        vector<long double> computed_area1, lin_func1, K1;
        vector<long double> computed_area2, lin_func2, K2;
        dsu(int n)
        {
            root.resize(n);
            sz.resize(n, 1);
            parts.resize(n);
            computed_area1.resize(n), lin_func1.resize(n), K1.resize(n);
            computed_area2.resize(n), lin_func2.resize(n), K2.resize(n);
            iota(root.begin(), root.end(), 0);
        }
        double compute_area1(int z, int v)
        {
            return sqr(MAXC - z) * 0.5 * K1[v] + computed_area1[v] + lin_func1[v] * (MAXC - z);
        }
        double compute_area2(int z, int v)
        {
            return - (sqr(z) * 0.5 * K2[v] + computed_area2[v] + lin_func2[v] * z);
        }
        int Root(int v)
        {
            if (v == root[v]) return v;
            return root[v] = Root(root[v]);
        }
        void Merge(int v, int u)
        {
            v = Root(v), u = Root(u);
            if (v == u) return;
            if (sz[v] > sz[u]) swap(v, u);
            sz[u] += sz[v];
            root[v] = u;
            parts[u] += parts[v];
            computed_area1[u] += computed_area1[v];
            computed_area2[u] += computed_area2[v];
            lin_func1[u] += lin_func1[v];
            lin_func2[u] += lin_func2[v];
            K1[u] += K1[v];
            K2[u] += K2[v];
        }
    };

    dsu D(m);

    for (int Cc = MAXC, pi = 0, qi = 0; Cc >= 0; Cc--)
    {
        while (qi < q && asks[qi].h >= Cc)
        {
            if (p[asks[qi].p].z <= asks[qi].h)
            {
                qi++;
                continue;
            }

            int v = in_faces[asks[qi].p][0];
            v = D.Root(v);

            asks[qi].answer = D.parts[v];
            asks[qi].answer += D.compute_area1(Cc, v);
            asks[qi].answer += D.compute_area2(Cc, v);

            qi++;
        }

        while (pi < n && p[pi].z == Cc)
        {
            for (auto face_id : in_faces[pi])
            {
                D.Merge(face_id, in_faces[pi][0]);
                int rt = D.Root(face_id);

                int cnt = points_on_face[face_id];
                points_on_face[face_id]++, cnt++;

                Point A = p[faces[face_id][0]];
                Point B = p[faces[face_id][1]];
                Point C = p[faces[face_id][2]];

                double area = sin(B, C, A) * dist(B, A) * dist(C, A) / 2;

                if (cnt == 1)
                {
                    double k = 2 * area / (A.z - C.z) / (A.z - B.z);
                    if (B.z == A.z) k = 0;

                    computed_area[face_id] = 0.5 * k * sqr(MAXC - A.z);
                    D.computed_area1[rt] += computed_area[face_id];
                    lin_func[face_id] = - k * (MAXC - A.z);
                    D.lin_func1[rt] += lin_func[face_id];
                    K[face_id] = k;
                    D.K1[rt] += K[face_id];
                }
                if (cnt == 2)
                {
                    double k = 2 * area / (A.z - C.z) / (B.z - C.z);
                    if (B.z == C.z) k = 0;

                    parts[face_id] = area;
                    D.parts[rt] += parts[face_id];

                    D.computed_area1[rt] -= computed_area[face_id];
                    computed_area[face_id] = 0.5 * k * sqr(C.z);
                    D.computed_area2[rt] += computed_area[face_id];
                    D.lin_func1[rt] -= lin_func[face_id];
                    lin_func[face_id] = - k * C.z;
                    D.lin_func2[rt] += lin_func[face_id];
                    D.K1[rt] -= K[face_id];
                    K[face_id] = k;
                    D.K2[rt] += K[face_id];
                }
                if (cnt == 3)
                {
                    D.parts[rt] -= parts[face_id];
                    parts[face_id] = area;
                    D.parts[rt] += parts[face_id];

                    D.computed_area2[rt] -= computed_area[face_id];
                    D.lin_func2[rt] -= lin_func[face_id];
                    D.K2[rt] -= K[face_id];
                }
            }

            pi++;
        }
    }

    // end of solution

    sort(all(asks), [&](Query a, Query b){
         return a.id < b.id;
         });

    for (int i = 0; i < q; i++)
    {
        if (p[asks[i].p].z <= asks[i].h)
            cout << -1 << "\n";
        else
            cout << setprecision(20) << asks[i].answer << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cout << setprecision(20);

    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}