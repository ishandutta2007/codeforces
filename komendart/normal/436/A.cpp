#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
    int n, x;
    vector< pair<int, int> > candies[2];
    
    cin >> n >> x;
    for (int i = 0; i < n; i += 1)
    {
        int t, h, m;
        cin >> t >> h >> m;
        candies[t].push_back(make_pair(h, m));
    }
    
    vector<int> used[2];
    for (int i = 0; i < 2; i += 1)
        for (int j = 0; j < candies[i].size(); j += 1)
        {
            used[i].push_back(0);
        }
    
    int result1 = 0;
    int cur = 0;
    int jump = x;
    
    while (true)
    {
        int max_i = -1;
        for (int i = 0; i < candies[cur].size(); i += 1)
        {
            if (!used[cur][i] && candies[cur][i].first <= jump &&
                (max_i == -1 || candies[cur][max_i].second < candies[cur][i].second))
            {
                max_i = i;
            }
        }
        
        if (max_i == -1) break;
        
        used[cur][max_i] = 1;
        jump += candies[cur][max_i].second;
        result1 += 1;
        
        cur = !cur;
    }
    
    for (int i = 0; i < 2; i += 1)
        for (int j = 0; j < candies[i].size(); j += 1)
        {
            used[i][j] = 0;
        }
    
    int result2 = 0;
    cur = 1;
    jump = x;
    
    while (true)
    {
        int max_i = -1;
        for (int i = 0; i < candies[cur].size(); i += 1)
        {
            if (!used[cur][i] && candies[cur][i].first <= jump &&
                (max_i == -1 || candies[cur][max_i].second < candies[cur][i].second))
            {
                max_i = i;
            }
        }
        
        if (max_i == -1) break;
        
        used[cur][max_i] = 1;
        jump += candies[cur][max_i].second;
        result2 += 1;
        
        cur = !cur;
    }
    
    cout << max(result1, result2) << endl;
    
}