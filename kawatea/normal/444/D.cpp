#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Hash {
    public:
    
    Hash(const char *s, unsigned long long base = 1000000007)
    {
        int n = strlen(s);
        
        hash = (unsigned long long *)malloc(sizeof(unsigned long long) * (n + 1));
        pow = (unsigned long long *)malloc(sizeof(unsigned long long) * (n + 1));
        
        hash[0] = 0;
        pow[0] = 1;
        
        for (int i = 0; i < n; i++) {
            hash[i + 1] = hash[i] * base + s[i];
            pow[i + 1] = pow[i] * base;
        }
    }
    
    ~Hash() {
        free(hash);
        free(pow);
    }
    
    unsigned long long get(int x, int y)
    {
        return hash[x + y] - hash[x] * pow[y];
    }
    
    private:
    
    unsigned long long *hash;
    unsigned long long *pow;
};

unsigned long long hash(char *s, int n)
{
    int i;
    unsigned long long x = 0;
    
    for (i = 0; i < n; i++) x = x * 1000000007 + s[i];
    
    return x;
}

bool in(char *s1, char *s2, int n1, int n2)
{
    int i, j;
    
    for (i = 0; i + n1 <= n2; i++) {
        for (j = 0; j < n1; j++) {
            if (s1[j] != s2[i + j]) break;
        }
        
        if (j == n1) return true;
    }
    
    return false;
}

char s[50001];
char s1[5];
char s2[5];

int main()
{
    int n, q, n1, n2, i, j;
    map <unsigned long long, vector <int> > mp, mp2;
    map <pair<unsigned long long, unsigned long long>, int> mp3;
    
    scanf("%s", s);
    
    n = strlen(s);
    
    Hash h(s);
    
    for (i = 1; i <= 4; i++) {
        for (j = n - i; j >= 0; j--) {
            unsigned long long x = h.get(j, i);
            
            mp[x].push_back(-j);
        }
        
        for (j = 0; i + j <= n; j++) {
            unsigned long long x = h.get(j, i);
            
            mp2[x].push_back(i + j);
        }
    }
    
    scanf("%d", &q);
    
    for (i = 0; i < q; i++) {
        int ans = 1e9;
        unsigned long long x, y;
        
        scanf("%s %s", s1, s2);
        
        n1 = strlen(s1);
        n2 = strlen(s2);
        
        x = hash(s1, n1);
        y = hash(s2, n2);
        
        if (mp3.count(make_pair(min(x, y), max(x, y)))) {
            printf("%d\n", mp3[make_pair(min(x, y), max(x, y))]);
            
            continue;
        }
        
        if (!mp.count(x) || !mp.count(y)) {
            puts("-1");
            
            continue;
        }
        
        if (n1 < n2) {
            if (in(s1, s2, n1, n2)) {
                printf("%d\n", n2);
                
                continue;
            }
        } else {
            if (in(s2, s1, n2, n1)) {
                printf("%d\n", n1);
                
                continue;
            }
        }
        
        if (mp[x].size() < mp2[y].size()) {
            for (j = mp[x].size() - 1; j >= 0; j--) {
                int z = lower_bound(mp2[y].begin(), mp2[y].end(), -mp[x][j] + max(n1, n2)) - mp2[y].begin();
                
                if (z == mp2[y].size()) break;
                
                ans = min(ans, mp[x][j] + mp2[y][z]);
            }
        } else {
            for (j = mp2[y].size() - 1; j >= 0; j--) {
                int z = lower_bound(mp[x].begin(), mp[x].end(), -mp2[y][j] + max(n1, n2)) - mp[x].begin();
                
                if (z == mp[x].size()) break;
                
                ans = min(ans, mp[x][z] + mp2[y][j]);
            }
        }
        
        swap(x, y);
        
        if (mp[x].size() < mp2[y].size()) {
            for (j = mp[x].size() - 1; j >= 0; j--) {
                int z = lower_bound(mp2[y].begin(), mp2[y].end(), -mp[x][j] + max(n1, n2)) - mp2[y].begin();
                
                if (z == mp2[y].size()) break;
                
                ans = min(ans, mp[x][j] + mp2[y][z]);
            }
        } else {
            for (j = mp2[y].size() - 1; j >= 0; j--) {
                int z = lower_bound(mp[x].begin(), mp[x].end(), -mp2[y][j] + max(n1, n2)) - mp[x].begin();
                
                if (z == mp[x].size()) break;
                
                ans = min(ans, mp[x][z] + mp2[y][j]);
            }
        }
        
        mp3[make_pair(min(x, y), max(x, y))] = ans;
        
        printf("%d\n", ans);
    }
    
    return 0;
}