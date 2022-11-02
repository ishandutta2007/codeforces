#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

template <class T>
class myset {
    public:

    myset()
    {
        top = NULL;
    }
    
    ~myset()
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
        return find(top, key) == -1 ? 0 : 1;
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
    
    typedef struct _myset {
        T key;
        int size;
        int height;
        struct _myset *child[2];
    } _myset;
    
    _myset *top;
    
    int size(_myset *s)
    {
        return s == NULL ? 0 : s->size;
    }
    
    int height(_myset *s)
    {
        return s == NULL ? 0 : s->height;
    }
    
    _myset *balance(_myset *s)
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
    
    _myset *rotate(_myset *s, int l, int r)
    {
        _myset *t = s->child[r];
        
        s->child[r] = t->child[l];
        t->child[l] = balance(s);
        
        if (s != NULL) s->size = size(s->child[0]) + size(s->child[1]) + 1;
        if (t != NULL) t->size = size(t->child[0]) + size(t->child[1]) + 1;
        
        return balance(t);
    }
    
    _myset *insert(_myset *s, T key)
    {
        if (s == NULL) {
            _myset *tmp = new _myset;
            
            tmp->key = key;
            tmp->size = 1;
            tmp->height = 1;
            tmp->child[0] = NULL;
            tmp->child[1] = NULL;
            
            return tmp;
        }
        
        if (key < s->key) {
            s->child[0] = insert(s->child[0], key);
        } else if (key == s->key) {
            return s;
        } else {
            s->child[1] = insert(s->child[1], key);
        }
        
        s->size++;
        
        return balance(s);
    }
    
    _myset *move_down(_myset *s, _myset *t)
    {
        if (s == NULL) return t;
        
        s->child[1] = move_down(s->child[1], t);
        
        return balance(s);
    }
    
    _myset *erase(_myset *s, T key)
    {
        if (s == NULL) return NULL;
        
        if (key < s->key) {
            s->child[0] = erase(s->child[0], key);
        } else if (key == s->key) {
            _myset *tmp = move_down(s->child[0], s->child[1]);
            
            delete s;
            
            return tmp;
        } else {
            s->child[1] = erase(s->child[1], key);
        }
        
        s->size--;
        
        return balance(s);
    }
    
    int find(_myset *s, T key)
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
    
    void clear(_myset *s)
    {
        if (s == NULL) return;
        
        if (s->child[0] != NULL) clear(s->child[0]);
        if (s->child[1] != NULL) clear(s->child[1]);
        
        delete s;
    }
    
    T rank(_myset *s, int n)
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
    
    int lower_bound(_myset *s, T key)
    {
        if (s == NULL) return 0;
        
        if (key <= s->key) {
            return lower_bound(s->child[0], key);
        } else {
            return size(s->child[0]) + 1 + lower_bound(s->child[1], key);
        }
    }
    
    int upper_bound(_myset *s, T key)
    {
        if (s == NULL) return 0;
        
        if (key < s->key) {
            return upper_bound(s->child[0], key);
        } else {
            return size(s->child[0]) + 1 + upper_bound(s->child[1], key);
        }
    }
};

int a[1000000];
int b[1000000];

int main()
{
    int n, m, sum = 0, i, j;
    myset <int> s;
    myset <pair<int, int> > s2;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) a[i] = -1;
    
    for (i = 0; i < n; i++) s.insert(i);
    
    for (i = 0; i < m; i++) {
        int x, y, z;
        
        scanf("%d %d", &x, &y);
        
        x--;
        y--;
        
        if (a[x] == -1) {
            if (sum > y) {
                puts("-1");
                
                return 0;
            }
            
            z = s.rank(y - sum);
            
            s.erase(z);
            
            sum++;
            
            b[z] = x + 1;
        } else {
            pair <int, int> p;
            
            if (y >= s2.size()) {
                puts("-1");
                
                return 0;
            }
            
            p = s2.rank(y);
            
            if (p.second != x) {
                puts("-1");
                
                return 0;
            }
            
            s2.erase(p);
        }
        
        a[x] = i;
        s2.insert(make_pair(-i, x));
    }
    
    for (i = 0, j = 0; i < n; i++) {
        if (a[i] == -1) {
            for (; j < n; j++) {
                if (b[j] == 0) {
                    b[j] = i + 1;
                    
                    break;
                }
            }
        }
    }
    
    for (i = 0; i < n; i++) {
        if (i > 0) putchar(' ');
        
        printf("%d", b[i]);
    }
    
    puts("");
    
    return 0;
}