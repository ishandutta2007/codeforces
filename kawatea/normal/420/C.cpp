#include <cstdio>
#include <iostream>
#include <map>
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

int a[300000];
map <int, int> mp[300000];

int main()
{
    int n, p, i;
    long long ans = 0;
    mymultiset <int> s;
    map <int, int>::iterator it;
    
    scanf("%d %d", &n, &p);
    
    for (i = 0; i < n; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        x--;
        y--;
        
        if (x > y) swap(x, y);
        
        a[x]++;
        a[y]++;
        mp[x][y]++;
    }
    
    for (i = 0; i < n; i++) s.insert(a[i]);
    
    for (i = 0; i < n; i++) {
        s.erase(a[i]);
        
        if (a[i] >= p) {
            ans += n - i - 1;
        } else {
            ans += s.size() - s.lower_bound(p - a[i]);
            
            for (it = mp[i].begin(); it != mp[i].end(); it++) {
                if (a[i] + a[it->first] >= p && a[i] + a[it->first] - it->second < p) ans--;
            }
        }
    }
    
    printf("%I64d\n", ans);
    
    return 0;
}