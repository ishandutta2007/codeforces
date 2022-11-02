#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

template <class T>
class mymultiset {
    public:
    
    typedef struct _mymultiset {
        T key;
        int size;
        int height;
        struct _mymultiset *child[2];
    } _mymultiset;
    
    _mymultiset *top;
    
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

vector <int> v[100000];
vector <pair<int, int> > w[100000];
int c[100000];
int ans[100000];

void dfs(int x, int y, map <int, int> &mp, mymultiset <int> &s)
{
    int i;
    
    for (i = 0; i < v[x].size(); i++) {
        if (v[x][i] != y) {
            map <int, int> mp2;
            mymultiset <int> s2;
            
            dfs(v[x][i], x, mp2, s2);
            
            if (mp.empty()) {
                mp.swap(mp2);
                swap(s.top, s2.top);
            } else if (mp.size() < mp2.size()) {
                map <int, int>::iterator it;
                
                for (it = mp.begin(); it != mp.end(); it++) {
                    if (mp2.count(it->first)) {
                        int p = mp2[it->first];
                        
                        mp2[it->first] += it->second;
                        s2.erase(p);
                        s2.insert(p + it->second);
                    } else {
                        mp2[it->first] = it->second;
                        s2.insert(it->second);
                    }
                }
                
                mp.swap(mp2);
                swap(s.top, s2.top);
            } else {
                map <int, int>::iterator it;
                
                for (it = mp2.begin(); it != mp2.end(); it++) {
                    if (mp.count(it->first)) {
                        int p = mp[it->first];
                        
                        mp[it->first] += it->second;
                        s.erase(p);
                        s.insert(p + it->second);
                    } else {
                        mp[it->first] = it->second;
                        s.insert(it->second);
                    }
                }
            }
        }
    }
    
    if (mp.count(c[x])) {
        int p = mp[c[x]];
        
        mp[c[x]]++;
        s.erase(p);
        s.insert(p + 1);
    } else {
        mp[c[x]]++;
        s.insert(1);
    }
    
    for (i = 0; i < w[x].size(); i++) {
        ans[w[x][i].first] = s.size() - s.lower_bound(w[x][i].second);
    }
}

int main()
{
    int n, m, i;
    map <int, int> mp;
    mymultiset <int> s;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) scanf("%d", &c[i]);
    
    for (i = 0; i < n - 1; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        x--;
        y--;
        
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    for (i = 0; i < m; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        w[x - 1].push_back(make_pair(i, y));
    }
    
    dfs(0, -1, mp, s);
    
    for (i = 0; i < m; i++) printf("%d\n", ans[i]);
    
    return 0;
}