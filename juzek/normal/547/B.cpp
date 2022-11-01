#include <bits/stdc++.h>
using namespace std;

int tab[200007];
stack<int>s;
stack<int>sr;

int l[200007];
int r[200007];

int maxi[200007];

int main()
{
    int N;
    scanf("%d",&N);
    for (int i = 1;i <= N;i++)
        scanf("%d",&tab[i]);

    for (int i = 1;i <= N;i++)
    {
        while (!s.empty() && tab[s.top()] >= tab[i])
            s.pop();
        if (s.empty())
            l[i] = 0;
        else
            l[i] = s.top();
        s.push(i);
    }

    for (int i = N;i > 0;i--)
    {
        while (!sr.empty() && tab[sr.top()] >= tab[i])
            sr.pop();
        if (sr.empty())
            r[i] = N+1;
        else
            r[i] = sr.top();
        sr.push(i);
    }

    for (int i = 1;i <= N;i++)
    {
        maxi[r[i]-l[i]-1] = max(maxi[r[i]-l[i]-1],tab[i]);
    }
    for (int i = N;i > 0;i--)
        maxi[i] = max(maxi[i],maxi[i+1]);
    for (int i = 1;i <= N;i++)
        printf("%d ",maxi[i]);


    return 0;
}