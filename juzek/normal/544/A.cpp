#include <bits/stdc++.h>
using namespace std;

queue<int>Q;

bool wyst[200];

int main()
{
    int k;
    cin >> k;
    string a;
    cin >> a;
    int N = a.length();
    int il = 0;
    for (int i = 0;i < N && il < k;i++)
    {
        if (wyst[a[i]] == false)
        {
            il++;
            Q.push(i);
            wyst[a[i]] = true;
        }
    }
    int w;
    if (il == k)
    {
        printf("YES");
        while (!Q.empty())
        {
            printf("\n");
            w = Q.front();
            Q.pop();
            if (Q.empty())
                for (;w < N;w++)
                    printf("%c",a[w]);
            else
            for (;w < Q.front();w++)
                printf("%c",a[w]);
        }
    }
    else
        printf("NO");

    return 0;
}