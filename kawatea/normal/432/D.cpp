#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
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
            hash[i + 1] = (hash[i] * base + s[i]) % 1000000007;
            pow[i + 1] = pow[i] * base % 1000000007;
        }
    }
    
    ~Hash() {
        free(hash);
        free(pow);
    }
    
    unsigned long long get(int x, int y)
    {
        return (hash[x + y] - hash[x] * pow[y] % 1000000007 + 1000000007) % 1000000007;
    }
    
    private:
    
    unsigned long long *hash;
    unsigned long long *pow;
};

int a[100001];
char s[100001];

int main()
{
    int n, i;
    vector <pair<int, int> > v;
    
    scanf("%s", s);
    
    Hash h(s, 31);
    Hash h2(s, 123456789);
    
    n = strlen(s);
    
    for (i = 0; i < n; i++) {
        int l, r, m;
        
        l = 0, r = n - i + 1, m = (l + r) / 2;
        
        while (r - l > 1) {
            if (h.get(i, m) == h.get(0, m) && h2.get(i, m) == h2.get(0, m)) {
                l = m;
                m = (l + r) / 2;
            } else {
                r = m;
                m = (l + r) / 2;
            }
        }
        
        a[l]++;
    }
    
    for (i = n; i > 0; i--) a[i - 1] += a[i];
    
    for (i = 1; i <= n; i++) {
        if (h.get(0, i) == h.get(n - i, i) && h2.get(0, i) == h2.get(n - i, i)) v.push_back(make_pair(i, a[i]));
    }
    
    printf("%d\n", v.size());
    
    for (i = 0; i < v.size(); i++) printf("%d %d\n", v[i].first, v[i].second);
    
    return 0;
}