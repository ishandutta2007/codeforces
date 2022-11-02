#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int x, y, a, b, i, j;
    vector <pair<int, int> > v;
    
    scanf("%d %d %d %d", &x, &y, &a, &b);
    
    for (i = a; i <= x; i++) {
        for (j = b; j <= y; j++) {
            if (i > j) v.push_back(make_pair(i, j));
        }
    }
    
    printf("%d\n", v.size());
    
    for (i = 0; i < v.size(); i++) printf("%d %d\n", v[i].first, v[i].second);
    
    return 0;
}