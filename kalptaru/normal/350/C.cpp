#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#define N 100020
using namespace std;
 
int x[N], y[N];
int p[N];
 
vector<pair<int, pair<int, char> > > v;
 
inline bool cmp(const int a, const int b)
{
    return abs(x[a]) + abs(y[a]) < abs(x[b]) + abs(y[b]);
}
 
int main(void)
{
    int n;
    int i;
 
    scanf("%d", &n);
    for(i = 0; i < n; i ++)
        scanf("%d %d", &x[i], &y[i]);
 
    for(i = 0; i < n; i ++)
        p[i] = i;
    sort(p, p + n, cmp);
 
    for(i = 0; i < n; i ++)
    {
        if(x[p[i]] > 0)
            v.push_back(make_pair(1, make_pair( x[p[i]], 'R')));
        if(x[p[i]] < 0)
            v.push_back(make_pair(1, make_pair(-x[p[i]], 'L')));
        if(y[p[i]] > 0)
            v.push_back(make_pair(1, make_pair( y[p[i]], 'U')));
        if(y[p[i]] < 0)
            v.push_back(make_pair(1, make_pair(-y[p[i]], 'D')));
 
        v.push_back(make_pair(2, make_pair(0, 0)));
 
        if(x[p[i]] > 0)
            v.push_back(make_pair(1, make_pair( x[p[i]], 'L')));
        if(x[p[i]] < 0)
            v.push_back(make_pair(1, make_pair(-x[p[i]], 'R')));
        if(y[p[i]] > 0)
            v.push_back(make_pair(1, make_pair( y[p[i]], 'D')));
        if(y[p[i]] < 0)
            v.push_back(make_pair(1, make_pair(-y[p[i]], 'U')));
 
        v.push_back(make_pair(3, make_pair(0, 0)));
    }
 
    printf("%d\n", (signed)v.size());
    for(i = 0; i < (signed)v.size(); i ++)
    {
        printf("%d ", v.at(i).first);
        if(v.at(i).first == 1)
            printf("%d %c", v.at(i).second.first, v.at(i).second.second);
        putchar('\n');
    }
 
    return 0;
}