#include <iostream>
#include <vector>
#include <set>
#include <map>


using namespace std;


map<pair<int, set<int>>, int> memory;


int count(int k, set<int> & s)
{
    int mem = memory[{k, s}]; 
    if (mem != 0)
    {
        if (mem == -1)
        {
            return 0;
        }
        return mem;
    }
    int ans = 0;
    vector<bool> mex(61, 0);
    for (int i = 1; i <= k; i++)
    {
        if (s.find(i) == s.end())
        {
            s.insert(i);
            mex[count(k - i, s)] = 1;
            s.erase(i);
        }
    }
    while (mex[ans])
    {
        ans++;
    }
    if (ans == 0)
        memory[{k, s}] = -1;
    else
        memory[{k, s}] = ans;
    return ans;
}


int main()
{
    int n;
    cin >> n;
    vector<int> heap(61, 0);
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        heap[k] ^= 1;
    }
    int ans = 0;
    vector<int> grandifunc = {0, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10};    
    for (int i = 1; i <= 60; i++)
    {
        if (heap[i])
        {
            ans ^= grandifunc[i];
        }
    }
    //cout << ans << endl;
    if (ans == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}