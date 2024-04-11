#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <deque>
#include <map>
#include <set>

using namespace std;

int main()
{
    int n, v;
    cin >> n >> v;
    
    int by_time[3002];
    
    for (int i = 0; i <= 3001; i += 1)
    {
        by_time[i] = 0;
    }
    
    for (int i = 0; i < n; i += 1)
    {
        int a, b;
        cin >> a >> b;
        by_time[a] += b;
    }
    
    int result = 0;
    
    for (int i = 1; i <= 3001; i += 1)
    {
        by_time[i] += min(v, by_time[i - 1]);
        result += min(by_time[i], v);
        by_time[i] = max(0, by_time[i] - v);
    }
    
    cout << result;
    
}