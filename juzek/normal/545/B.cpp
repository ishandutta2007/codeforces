#include <bits/stdc++.h>
using namespace std;

bool v[100007];

int main()
{
    string a;
    string b;
    cin >> a >> b;
    bool q = true;
    int N = a.length();
    int il = 0;
    for (int i = 0;i < N;i++)
    {
        if (a[i] == b[i])
            v[i] = a[i]-'0';
        else if (q)
        {
            v[i] = a[i]-'0';
            q = !q;
            il++;
        }
        else
        {
            v[i] = b[i]-'0';
            q = !q;
            il++;
        }
    }
    if (il%2)
    {
        printf("impossible");
        return 0;
    }
    for (int i = 0;i < N;i++)
        printf("%d",v[i]);
    return 0;
}