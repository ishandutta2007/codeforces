#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Bit {
    public:
    
    Bit(int n) {
        size = n + 1;
        bit = (long long *)calloc(size, sizeof(long long));
    }
    
    ~Bit() {
        free(bit);
    }
    
    void add(int x, long long v) {
        for (x++; x < size; x += x & -x) bit[x] += v;
    }
    
    //[0,x]
    long long sum(int x) {
        long long s = 0;
        
        for (x++; x > 0; x -= x & -x) s += bit[x];
        
        return s;
    }
    
    //[x,y]
    long long get(int x, int y) {
        return sum(y) - sum(x - 1);
    }
    
    private:
    
    int size;
    long long *bit;
};

int a[200000];
int ans[200000];

int main()
{
    int n, last = -1, i, j;
    vector <pair<int, int> > v;
    vector <int> w;
    map <int, int> mp;
    map <int, int>::iterator it;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        
        mp[a[i]] = 0;
    }
    
    for (it = mp.begin(), i = 0; it != mp.end(); it++, i++) it->second = i;
    
    for (i = 0; i < n; i++) v.push_back(make_pair(mp[a[i]], i));
    
    sort(v.begin(), v.end());
    
    Bit b(n + 1);
    
    for (i = 0; i < n; i++) {
        int x = v[i].second;
        int y = v[i].first;
        
        if (last != y) {
            for (j = 0; j < w.size(); j++) b.add(w[j], 1);
            
            w.clear();
        }
        
        last = y;
        
        for (j = 1; j < n; j++) {
            long long p = (long long)j * x + 2;
            long long q = (long long)j * (x + 1) + 1;
            
            if (p > n) break;
            
            q = min(q, (long long)n);
            
            ans[j - 1] += b.get(p - 1, q - 1);
        }
        
        w.push_back(x);
    }
    
    for (i = 0; i < n - 1; i++) {
        if (i > 0) putchar(' ');
        
        printf("%d", ans[i]);
    }
    
    puts("");
    
    return 0;
}