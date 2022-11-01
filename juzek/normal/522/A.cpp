#include <bits/stdc++.h>
using namespace std;

int tab[50] = {30803, 30809, 30817, 30829, 30839, 30841, 30851, 30853, 30859, 30869, 28649, 28657, 28661, 28663, 28669, 28687, 28697, 28703, 28711, 28723,94349, 94351, 94379, 94397, 94399, 94421, 94427, 94433, 94439, 94441};

vector<int>v[100060];

int toInt(string a)
{
    int N = a.length();
    long long odp = 1;
    for (int i = 0;i < N;i++)
    {
        if (a[i] >= 'A' && a[i] <= 'Z')
            a[i] += 'a'-'A';
        a[i] += 4;
        odp += a[i]*tab[i];
        odp %= 100043;
        odp *= tab[i];
        odp %= 100043;
        odp *= tab[i+1];
        odp %= 100043;
    }
    return odp;
}

int DFS(int a)
{
    int maxodl = 0;
    for (int i = 0;i < v[a].size();i++)
    {
        maxodl = max(maxodl,DFS(v[a][i]));
    }
    return maxodl+1;
}

int main()
{
    int N;
    scanf("%d",&N);
    string a,b;
    int ia,ib;
    for (int i = 0;i < N;i++)
    {
        cin >> a;
        ia = toInt(a);
        cin >> a >> b;
        ib = toInt(b);
        //printf("%d %d\n",ia,ib);
        v[ib].push_back(ia);
    }
    printf("%d",DFS(43798));
    return 0;
}