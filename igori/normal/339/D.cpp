#include <iostream>

using namespace std;

int n, m;
bool fi[(1 << 18)];

bool op(int v)
{
    return fi[v];
}

struct Tree{
    int a[(1 << 18)];
    void build(int v)
    {
        if (a[v] != -1)
            return;
        build(2 * v);
        build(2 * v + 1);
        if (op(v) == 1)
            a[v] = a[2 * v] | a[2 * v + 1];
        else
            a[v] = a[2 * v] ^ a[2 * v + 1];
    }
    void ch(int i, int v, int l, int r, int id)
    {
        int m = (l + r) / 2;
        //cout << id << " " << l << " " << r << endl << endl;
        if (l == i && r == i + 1)
        {
            a[id] = v;
            return;
        }
        if (i < m)
        {
            ch(i, v, l, m, id * 2);
        }
        else
        {
            ch(i, v, m, r, id * 2 + 1);
        }
        if (op(id) == 1)
            a[id] = a[2 * id] | a[2 * id + 1];
        else
            a[id] = a[2 * id] ^ a[2 * id + 1];
        //cout << id << " " << l << " " << r << " " << a[id] << " " << a[2 * id] << " " << a[2 * id + 1] << endl;
    }
    Tree(){
        for (int i = 0; i < (1 << 18); i++)
            a[i] = -1;
    }
}T;

int main()
{
    //freopen("stdin.in", "r", stdin);
    //freopen("stdout.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = (1 << n) - 1; i >= 1; i--)
    {
        fi[i] = 1 ^ fi[2 * i];
    }
    for (int i = 0; i < (1 << n); i++)
    {
        cin >> T.a[i + (1 << n)];
    }
    T.build(1);
    while(m--)
    {
        int i, a;
        cin >> i >> a;
        i--;
        T.ch(i, a, 0, (1 << n), 1);
        cout << T.a[1] << "\n";
    }
}