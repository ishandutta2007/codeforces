#include <cstdio>
#include <iostream>
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
        if (top == NULL) {
            return true;
        } else {
            return false;
        }
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
        
        if (tmp == -1) tmp = size(top);
        
        return tmp;
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
        int tmp = lower_bound(top, key);
        
        if (tmp == -1) tmp = size(top);
        
        return tmp;
    }
    
    int upper_bound(T key)
    {
        int tmp = upper_bound(top, key);
        
        if (tmp == -1) tmp = size(top);
        
        return tmp;
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
        if (s == NULL) {
            return 0;
        } else {
            return s->size;
        }
    }
    
    int height(_mymultiset *s)
    {
        if (s == NULL) {
            return 0;
        } else {
            return s->height;
        }
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
            if (height(s->child[0]) > height(s->child[1])) {
                s->height = height(s->child[0]) + 1;
            } else {
                s->height = height(s->child[1]) + 1;
            }
            
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
        if (s == NULL) return -1;
        
        if (key <= s->key) {
            int tmp = lower_bound(s->child[0], key);
            
            if (tmp == -1) {
                return size(s->child[0]);
            } else {
                return tmp;
            }
        } else {
            int tmp = lower_bound(s->child[1], key);
            
            if (tmp == -1) {
                return tmp;
            } else {
                return size(s->child[0]) + tmp + 1;
            }
        }
    }
    
    int upper_bound(_mymultiset *s, T key)
    {
        if (s == NULL) return -1;
        
        if (key < s->key) {
            int tmp = upper_bound(s->child[0], key);
            
            if (tmp == -1) {
                return size(s->child[0]);
            } else {
                return tmp;
            }
        } else {
            int tmp = upper_bound(s->child[1], key);
            
            if (tmp == -1) {
                return tmp;
            } else {
                return size(s->child[0]) + tmp + 1;
            }
        }
    }
};

int a[100000], b[100000];
int p[100001], q[100001];

int main()
{
    int n, i;
    mymultiset <int> s1, s2;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        
        p[a[i]] = i;
    }
    
    for (i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        
        q[b[i]] = i;
    }
    
    for (i = 1; i <= n; i++) {
        if (p[i] <= q[i]) {
            s1.insert(q[i] - p[i]);
        } else {
            s2.insert(p[i] - q[i]);
        }
    }
    
    for (i = 0; i < n; i++) {
        int x = 1e9;
        
        if (s1.size() > 0) x = min(x, s1.rank(0) - i);
        if (s2.size() > 0) x = min(x, s2.rank(0) + i);
        
        printf("%d\n", x);
        
        while (!s1.empty()) {
            if (s1.rank(0) > i) break;
            
            s1.erase(i);
            
            s2.insert(-i);
        }
        
        s2.erase(p[b[i]] - i);
        
        s1.insert(n - p[b[i]] + i);
    }
    
    return 0;
}