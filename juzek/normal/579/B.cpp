#include <bits/stdc++.h>
using namespace std;

vector<pair<int,pair<int,int> > >v;

int tab[807];


int main()
{
    int N;
    scanf("%d",&N);
    N *= 2;
    int a;
    for (int i = 2;i <= N;i++)
    {
        for (int w = 1;w < i;w++)
        {
            scanf("%d",&a);
            v.push_back(make_pair(a,make_pair(w,i)));
        }
    }
    sort(v.begin(),v.end());
    for (int i = v.size()-1;i >= 0;i--)
    {
        if (tab[v[i].second.first] == 0 && tab[v[i].second.second] == 0)
        {
            tab[v[i].second.first] = v[i].second.second; tab[v[i].second.second] = v[i].second.first;
        }
    }
    for (int i = 1;i <= N;i++)
    {
        printf("%d ",tab[i]);
    }
    return 0;
}