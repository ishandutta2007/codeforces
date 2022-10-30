#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int n, i;
    vector <int> v[3];
    vector <pair<int, pair<int, int> > > ans;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        v[x - 1].push_back(i + 1);
    }
    
    for (i = 0; i < v[0].size() && i < v[1].size() && i < v[2].size(); i++) {
        ans.push_back(make_pair(v[0][i], make_pair(v[1][i], v[2][i])));
    }
    
    printf("%d\n", ans.size());
    
    for (i = 0; i < ans.size(); i++) printf("%d %d %d\n", ans[i].first, ans[i].second.first, ans[i].second.second);
    
    return 0;
}