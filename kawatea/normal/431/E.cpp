#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <class T>
class mymultiset {
    public:

    mymultiset()
    {
        top = NULL;
    }
    
    ~mymultiset()
    {
        clear(top);
    }
    
    bool empty(void)
    {
        return top == NULL;
    }
    
    int size(void)
    {
        return size(top);
    }
    
    void insert(T key)
    {
        top = insert(top, key);
    }
    
    void erase(T key)
    {
        top = erase(top, key);
    }
    
    int find(T key)
    {
        int tmp = find(top, key);
        
        return tmp == -1 ? size(top) : tmp;
    }
    
    int count(T key)
    {
        return upper_bound(key) - lower_bound(key);
    }
    
    void clear(void)
    {
        clear(top);
        top = NULL;
    }
    
    T rank(int n)
    {
        return rank(top, n);
    }
    
    int lower_bound(T key)
    {
        return lower_bound(top, key);
    }
    
    int upper_bound(T key)
    {
        return upper_bound(top, key);
    }
    
    private:
    
    typedef struct _mymultiset {
        T key;
        int size;
        int height;
        struct _mymultiset *child[2];
    } _mymultiset;
    
    _mymultiset *top;
    
    int size(_mymultiset *s)
    {
        return s == NULL ? 0 : s->size;
    }
    
    int height(_mymultiset *s)
    {
        return s == NULL ? 0 : s->height;
    }
    
    _mymultiset *balance(_mymultiset *s)
    {
        for (int i = 0; i < 2; i++) {
            if (height(s->child[!i]) - height(s->child[i]) < -1) {
                if (height(s->child[i]->child[!i]) - height(s->child[i]->child[i]) > 0) {
                    s->child[i] = rotate(s->child[i], i, !i);
                }
                
                return rotate(s, !i, i);
            }
        }
        
        if (s != NULL) {
            s->height = max(height(s->child[0]), height(s->child[1])) + 1;
            s->size = size(s->child[0]) + size(s->child[1]) + 1;
        }
        
        return s;
    }
    
    _mymultiset *rotate(_mymultiset *s, int l, int r)
    {
        _mymultiset *t = s->child[r];
        
        s->child[r] = t->child[l];
        t->child[l] = balance(s);
        
        if (s != NULL) s->size = size(s->child[0]) + size(s->child[1]) + 1;
        if (t != NULL) t->size = size(t->child[0]) + size(t->child[1]) + 1;
        
        return balance(t);
    }
    
    _mymultiset *insert(_mymultiset *s, T key)
    {
        if (s == NULL) {
            _mymultiset *tmp = new _mymultiset;
            
            tmp->key = key;
            tmp->size = 1;
            tmp->height = 1;
            tmp->child[0] = NULL;
            tmp->child[1] = NULL;
            
            return tmp;
        }
        
        if (key <= s->key) {
            s->child[0] = insert(s->child[0], key);
        } else {
            s->child[1] = insert(s->child[1], key);
        }
        
        s->size++;
        
        return balance(s);
    }
    
    _mymultiset *move_down(_mymultiset *s, _mymultiset *t)
    {
        if (s == NULL) return t;
        
        s->child[1] = move_down(s->child[1], t);
        
        return balance(s);
    }
    
    _mymultiset *erase(_mymultiset *s, T key)
    {
        if (s == NULL) return NULL;
        
        if (key < s->key) {
            s->child[0] = erase(s->child[0], key);
        } else if (key == s->key) {
            _mymultiset *tmp = move_down(s->child[0], s->child[1]);
            
            delete s;
            
            return tmp;
        } else {
            s->child[1] = erase(s->child[1], key);
        }
        
        s->size--;
        
        return balance(s);
    }
    
    int find(_mymultiset *s, T key)
    {
        if (s == NULL) return -1;
        
        if (key < s->key) {
            return find(s->child[0], key);
        } else if (key == s->key) {
            return size(s->child[0]);
        } else {
            int tmp = find(s->child[1], key);
            
            if (tmp >= 0) tmp += size(s->child[0]) + 1;
            
            return tmp;
        }
    }
    
    void clear(_mymultiset *s)
    {
        if (s == NULL) return;
        
        if (s->child[0] != NULL) clear(s->child[0]);
        if (s->child[1] != NULL) clear(s->child[1]);
        
        delete s;
    }
    
    T rank(_mymultiset *s, int n)
    {
        int m = size(s->child[0]);
        
        if (n < m) {
            return rank(s->child[0], n);
        } else if (n == m) {
            return s->key;
        } else {
            return rank(s->child[1], n - m - 1);
        }
    }
    
    int lower_bound(_mymultiset *s, T key)
    {
        if (s == NULL) return 0;
        
        if (key <= s->key) {
            return lower_bound(s->child[0], key);
        } else {
            return size(s->child[0]) + 1 + lower_bound(s->child[1], key);
        }
    }
    
    int upper_bound(_mymultiset *s, T key)
    {
        if (s == NULL) return 0;
        
        if (key < s->key) {
            return upper_bound(s->child[0], key);
        } else {
            return size(s->child[0]) + 1 + upper_bound(s->child[1], key);
        }
    }
};

class Bit {
    public:
    
    Bit(int n)
    {
        size = n + 1;
        high = 1 << (31 - __builtin_clz(n));
        bit = (long long *)calloc(size, sizeof(long long));
    }
    
    ~Bit() {
        free(bit);
    }
    
    void add(int x, long long v)
    {
        for (x++; x < size; x += x & -x) bit[x] += v;
    }
    
    long long sum(int x)
    {
        long long s = 0;
        
        for (x++; x > 0; x -= x & -x) s += bit[x];
        
        return s;
    }
    
    private:
    
    int size;
    int high;
    long long *bit;
};

int a[100000];
long long b[100000][3];

int main()
{
    int n, q, i;
    vector <int> v;
    mymultiset <int> s;
    
    scanf("%d %d", &n, &q);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        
        v.push_back(a[i]);
        s.insert(a[i]);
    }
    
    for (i = 0; i < q; i++) {
        scanf("%I64d", &b[i][0]);
        
        if (b[i][0] == 1) {
            scanf("%I64d %I64d", &b[i][1], &b[i][2]);
            
            b[i][1]--;
            v.push_back(b[i][2]);
        } else {
            scanf("%I64d", &b[i][1]);
        }
    }
    
    sort(v.begin(), v.end());
    
    Bit bit(v.size());
    Bit bit2(v.size());
    
    for (i = 0; i < n; i++) {
        int x = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
        
        bit.add(x, a[i]);
        bit2.add(x, 1);
    }
    
    for (i = 0; i < q; i++) {
        if (b[i][0] == 1) {
            int x = lower_bound(v.begin(), v.end(), a[b[i][1]]) - v.begin();
            
            s.erase(a[b[i][1]]);
            bit.add(x, -a[b[i][1]]);
            bit2.add(x, -1);
            
            x = lower_bound(v.begin(), v.end(), b[i][2]) - v.begin();
            
            a[b[i][1]] = b[i][2];
            s.insert(b[i][2]);
            bit.add(x, b[i][2]);
            bit2.add(x, 1);
        } else {
            int l = 0, r = v.size() - 1, m = (l + r) / 2;
            
            while (r - l > 1) {
                int x = bit2.sum(m);
                int y;
                
                if (x == n) {
                    r = m;
                    m = (l + r) / 2;
                    
                    continue;
                }
                
                y = s.rank(x);
                
                if (bit.sum(m) + b[i][1] <= (long long)x * y) {
                    r = m;
                    m = (l + r) / 2;
                } else {
                    l = m;
                    m = (l + r) / 2;
                }
            }
            
            printf("%lf\n", (double)(bit.sum(r) + b[i][1]) / bit2.sum(r));
        }
    }
    
    return 0;
}