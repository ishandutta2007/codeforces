#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int p;
vector <pair<int, pair<int, pair<int, int> > > > v;

void check(string &s)
{
    int i, j, k, l;
    
    for (i = 1; i < 4 && i < s.size(); i++) {
        int x = 0;
        
        for (l = 0; l < i; l++) {
            x *= 10;
            x += s[l] - '0';
        }
        
        if (x > 255 || (s[0] == '0' && i > 1)) continue;
        
        for (j = i + 1; j < i + 4 && j < s.size(); j++) {
            int y = 0;
            
            for (l = i; l < j; l++) {
                y *= 10;
                y += s[l] - '0';
            }
            
            if (y > 255 || (s[i] == '0' && j > i + 1)) continue;
            
            for (k = j + 1; k < j + 4 && k < s.size(); k++) {
                int z = 0, w = 0;
                
                for (l = j; l < k; l++) {
                    z *= 10;
                    z += s[l] - '0';
                }
                
                if (z > 255 || (s[j] == '0' && k > j + 1)) continue;
                
                for (l = k; l < s.size(); l++) {
                    w *= 10;
                    w += s[l] - '0';
                }
                
                if (w > 255 || (s[k] == '0' && s.size() > k + 1)) continue;
                
                v.push_back(make_pair(x, make_pair(y, make_pair(z, w))));
            }
        }
    }
}

void dfs(int x, string &s)
{
    int i;
    
    if (s.size() >= 4 && (x ^ p) == 0) {
        check(s);
    }
    
    if (s.size() >= 11) return;
    
    for (i = 0; i < 10; i++) {
        if ((p >> i) & 1) {
            string t = "";
            
            t += i + '0';
            t += s;
            t += i + '0';
            
            dfs(x | (1 << i), t);
            
            if (s == "") {
                t = i + '0';
                
                dfs(x | (1 << i), t);
            }
        }
    }
}

int main()
{
    int n, i;
    string s = "";
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        p |= (1 << x);
    }
    
    if (n > 6) {
        puts("0");
        
        return 0;
    }
    
    dfs(0, s);
    
    printf("%d\n", v.size());
    
    for (i = 0; i < v.size(); i++) printf("%d.%d.%d.%d\n", v[i].first, v[i].second.first, v[i].second.second.first, v[i].second.second.second);
    
    return 0;
}