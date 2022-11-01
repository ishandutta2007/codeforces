#include <bits/stdc++.h>
using namespace std;

vector<int>v;

int main()
{
    int N;
    scanf("%d",&N);
    bool czy;
    int a;
    for (int i = 1;i <= N;i++)
    {
        czy = true;
        for (int w = 0;w < N;w++)
        {
            scanf("%d",&a);
            if (a == 1 || a == 3)
                czy = false;
        }
        if (czy)
            v.push_back(i);
    }
    printf("%d\n",(int)v.size());
    for (int i = 0;i < v.size();i++)
        printf("%d ",v[i]);
    return 0;
}