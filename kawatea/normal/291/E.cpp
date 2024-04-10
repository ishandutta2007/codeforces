#include <iostream>
#include <vector>
#include <string>

using namespace std;

int len, sum = 0;
unsigned long long base = 1000000007;
unsigned long long value;
unsigned long long pow[300001];
unsigned long long hash[300001];
vector <pair<int, string> > v[100000];

void dfs(int x, int y)
{
    int i, j;
    
    for (i = 0; i < v[x].size(); i++) {
        for (j = 0; j < v[x][i].second.size(); j++) {
            hash[y + j] = hash[y + j - 1] * base + v[x][i].second[j];
            
            if (y + j >= len && hash[y + j] - hash[y + j - len] * pow[len] == value) sum++;
        }
        
        dfs(v[x][i].first, y + v[x][i].second.size());
    }
}

int main()
{
    int n, i, j;
    string t;
    
    pow[0] = 1;
    
    for (i = 0; i < 300000; i++) pow[i + 1] = pow[i] * base;
    
    cin >> n;
    
    for (i = 1; i < n; i++) {
        int x;
        string s;
        
        cin >> x >> s;
        
        v[x - 1].push_back(make_pair(i, s));
    }
    
    cin >> t;
    
    for (i = 0; i < t.size(); i++) value = value * base + t[i];
    
    len = t.size();
    
    dfs(0, 1);
    
    cout << sum << endl;
    
    return 0;
}