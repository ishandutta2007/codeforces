#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = (1 << 20);
int d1[2 * N - 1];
pair<int, int> d2[2 * N - 1];
pair<int, int> d3[2 * N - 1];
char s[1000001];
int a[1000001];

inline void lazy(int k, int l, int r)
{
    if (k < N - 1) {
        d1[k * 2 + 1] += d1[k];
        d1[k * 2 + 2] += d1[k];
    }
    
    d2[k].first += d1[k];
    d3[k].first += d1[k];
    d1[k] = 0;
}

void update(int a, int b, int v, int k, int l, int r)
{
    lazy(k, l, r);
    
    if (r <= a || b <= l) return;
    
    if (a <= l && r <= b) {
        d1[k] += v;
        
        lazy(k, l, r);
        
        return;
    } else {
        update(a, b, v, k * 2 + 1, l, (l + r) / 2);
        update(a, b, v, k * 2 + 2, (l + r) / 2, r);
        
        d2[k] = min(d2[k * 2 + 1], d2[k * 2 + 2]);
        d3[k] = max(d3[k * 2 + 1], d3[k * 2 + 2]);
    }
}

pair<int, int> min_query(int a, int b, int k, int l, int r)
{
    pair<int, int> ans;
    
    lazy(k, l, r);
    
    if (r <= a || b <= l) return make_pair(1e9, 0);
    
    if (a <= l && r <= b) return d2[k];
    
    ans = min(min_query(a, b, k * 2 + 1, l, (l + r) / 2), min_query(a, b, k * 2 + 2, (l + r) / 2, r));
    
    d2[k] = min(d2[k * 2 + 1], d2[k * 2 + 2]);
    d3[k] = max(d3[k * 2 + 1], d3[k * 2 + 2]);
    
    return ans;
}

pair<int, int> max_query(int a, int b, int k, int l, int r)
{
    pair<int, int> ans;
    
    lazy(k, l, r);
    
    if (r <= a || b <= l) return make_pair(-1e9, 0);
    
    if (a <= l && r <= b) return d3[k];
    
    ans = max(max_query(a, b, k * 2 + 1, l, (l + r) / 2), max_query(a, b, k * 2 + 2, (l + r) / 2, r));
    
    d2[k] = min(d2[k * 2 + 1], d2[k * 2 + 2]);
    d3[k] = max(d3[k * 2 + 1], d3[k * 2 + 2]);
    
    return ans;
}

int main()
{
    int n, i;
    
    scanf("%s", s);
    
    n = strlen(s);
    
    if (s[n - 1] == 'L') {
        for (i = 0; i < n; i++) {
            if (s[i] == 'L') {
                s[i] = 'R';
            } else {
                s[i] = 'L';
            }
        }
    }
    
    for (i = 0; i < n; i++) {
        if (s[i] == 'L') {
            a[i + 1] = a[i] - 1;
        } else {
            a[i + 1] = a[i] + 1;
        }
    }
    
    for (i = 0; i < n; i++) {
        if (a[i] >= a[n]) break;
    }
    
    if (i == n) {
        puts("1");
        
        return 0;
    }
    
    for (i = 0; i < 2 * N - 1; i++) {
        d2[i] = make_pair(1e9, 0);
        d3[i] = make_pair(-1e9, 0);
    }
    
    for (i = 0; i < n; i++) {
        d2[i + N - 1] = d3[i + N - 1] = make_pair(a[i], i);
    }
    
    for (i = N - 2; i >= 0; i--) {
        d2[i] = min(d2[i * 2 + 1], d2[i * 2 + 2]);
        d3[i] = max(d3[i * 2 + 1], d3[i * 2 + 2]);
    }
    
    for (i = 0; ; i++) {
        if (max_query(0, n, 0, 0, N).first < a[n] + i) {
            printf("%d\n", -min_query(0, n, 0, 0, N).first + 1);
            
            return 0;
        } else {
            pair<int, int> p = min_query(0, n, 0, 0, N);
            
            if (p.first >= 0) {
                puts("0");
                
                return 0;
            }
            
            update(p.second, n, 1, 0, 0, N);
        }
    }
    
    return 0;
}