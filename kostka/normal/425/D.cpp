//Bartosz Kostka
//You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXD = 100007;
pair <int, int> tmp;
set <pair <int, int> > A, K[MAXD];
set <int> PX, PY;
vector <pair <int, int> > X[MAXD], Y[MAXD];

bool exist(pair <int, int> a)
{
    return (A.find(a) != A.end());
}

void print(pair <int, int> a)
{
    printf("%d %d ", a.first, a.second);
}

void printsquare (pair <int, int> a, pair <int, int> b, pair <int, int> c, pair <int, int> d)
{
    return;
    printf("[");
    print(a);
    print(b);
    print(c);
    print(d);
    printf("]\n");
}

void test()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d%d", &tmp.first, &tmp.second);
        A.insert(tmp);
        PX.insert(tmp.first);
        PY.insert(tmp.second);
        X[tmp.first].push_back(tmp);
        Y[tmp.second].push_back(tmp);
    }
    for(set<int>::iterator px = PX.begin(); px != PX.end(); px++)
        sort(X[*px].begin(), X[*px].end());
    for(set<int>::iterator py = PY.begin(); py != PY.end(); py++)
        sort(Y[*py].begin(), Y[*py].end());
    long long wyn = 0;
    for(set <pair <int,int> >::iterator it = A.begin(); it != A.end(); it++)
    {
        int x = (*it).first, y = (*it).second;
        if(X[x].size() < Y[y].size())
        {
            for(int i=0; i<X[x].size(); i++)
            {
                if(X[x][i] <= (*it))
                    continue;
                int side = X[x][i].second - (*it).second;
                pair <int, int> p, q;
                p.first = (*it).first + side;
                p.second = (*it).second;
                q.first = (*it).first + side;
                q.second = (*it).second + side;
                if(exist(p) && exist(q))
                {
                    printsquare(*it, X[x][i], p, q);
                    wyn++;
                }
            }
        }
        else
        {
            for(int i=0; i<Y[y].size(); i++)
            {
                if(Y[y][i] <= (*it))
                    continue;
                int side = Y[y][i].first - (*it).first;
                pair <int, int> p, q;
                p.first = (*it).first;
                p.second = (*it).second + side;
                q.first = (*it).first + side;
                q.second = (*it).second + side;
                if(exist(p) && exist(q))
                {
                    printsquare(*it, Y[y][i], p, q);
                    wyn++;
                }
            }
        }
    }
    printf("%lld\n", wyn);
}

int main()
{
    int t = 1;
    while(t--)
        test();
    return 0;
}