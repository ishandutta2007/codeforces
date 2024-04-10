#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int n1, n2;
char s1[100001], s2[100001];
map <int, int> mp;
vector <pair<int, int> > v;
vector <int> w;

void dfs(int x, int y)
{
    if (x == v.size()) {
        w.push_back(y);
    } else {
        int i;
        
        dfs(x + 1, y);
        
        for (i = 0; i < v[x].second; i++) {
            y *= v[x].first;
            
            dfs(x + 1, y);
        }
    }
}

bool check(int n)
{
    int i;
    char s[100001];
    
    strncpy(s, s1, n);
    
    for (i = 0; i < n1; i += n) {
        if (strncmp(s, s1 + i, n) != 0) return false;
    }
    
    for (i = 0; i < n2; i += n) {
        if (strncmp(s, s2 + i, n) != 0) return false;
    }
    
    return true;
}

int main()
{
    int n, sum = 0, i;
    
    scanf("%s", s1);
    scanf("%s", s2);
    
    n1 = strlen(s1);
    n2 = strlen(s2);
    
    n = n1;
    
    for (i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int c = 0;
            
            while (n % i == 0) {
                n /= i;
                c++;
            }
            
            mp[i] = c;
        }
    }
    
    if (n > 1) mp[n] = 1;
    
    n = n2;
    
    for (i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int c = 0;
            
            while (n % i == 0) {
                n /= i;
                c++;
            }
            
            if (mp.count(i) == 1) v.push_back(make_pair(i, min(mp[i], c)));
        }
    }
    
    if (n > 1 && mp.count(n) == 1) v.push_back(make_pair(n, 1));
    
    dfs(0, 1);
    
    for (i = 0; i < w.size(); i++) {
        if (check(w[i])) sum++;
    }
    
    printf("%d\n", sum);
    
    return 0;
}