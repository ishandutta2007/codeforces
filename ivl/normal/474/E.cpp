#include <cstdio>
#include <vector>
#define x first
#define y second
#include <algorithm>

using namespace std;

pair < int, int > tur[1 << 18];
void add(int pos, pair < int, int > val, int cpos = 1, int lo = 0, int hi = (1 << 17) - 1){
     if (pos < lo || pos > hi) return;
     if (lo == hi){tur[cpos] = val; return;}
     add(pos, val, cpos * 2, lo, (lo + hi) / 2);
     add(pos, val, cpos * 2 + 1, (lo + hi + 1) / 2, hi);
     tur[cpos] = max(tur[cpos * 2], tur[cpos * 2 + 1]);
}
int slo, shi;
pair < int, int > query(int cpos = 1, int lo = 0, int hi = (1 << 17) - 1){
     if (lo > shi || hi < slo) return make_pair(-1, -1);
     if (lo >= slo && hi <= shi) return tur[cpos];
     return max(
            query(cpos * 2, lo, (lo + hi) / 2),
            query(cpos * 2 + 1, (lo + hi + 1) / 2, hi));
}

long long n, d;
long long h[100005];
vector < pair < long long, int > > v;
int inv[100005];

int prev[100005];

int main(){
    scanf("%I64d%I64d", &n, &d);
    for (int i = 0; i < n; ++i){
        scanf("%I64d", h + i);
        v.push_back(make_pair(h[i], i));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; ++i) inv[v[i].y] = i;
    
    for (int i = 0; i < n; ++i){
        
        int l, r;
        long long t = h[i] - d;
        int lo = 0, hi = n - 1, mid = (lo + hi + 1) / 2;
        while (lo != hi){
              if (v[mid].x > t) hi = mid - 1;
              else lo = mid;
              mid = (lo + hi + 1) / 2;
        }
        l = mid;
        
        t += 2 * d;
        lo = 0;
        hi = n - 1;
        mid = (lo + hi) / 2;
        while (lo != hi){
              if (v[mid].x < t) lo = mid + 1;
              else hi = mid;
              mid = (lo + hi) / 2;
        }
        r = mid;
        /*
        printf("%d ->\n", i + 1);
        printf("   %d [%d]\n", l, v[l].x);
        printf("   %d [%d]\n", r, v[r].x);
        */
        pair < int, int > qr1 = make_pair(0, 0);
        if (v[0].x <= h[i] - d){
           slo = 0;
           shi = l;
           qr1 = query();
        }
        pair < int, int > qr2 = make_pair(0, 0);
        if (v.back().x >= h[i] + d){
           slo = r;
           shi = n - 1;
           qr2 = query();
        }
        
        pair < int, int > q = max(qr1, qr2);
        
        pair < int, int > q2 = q;
        ++q2.x;
        q2.y = i;
        prev[i] = q.y;
        add(inv[i], q2);
        
    }
    
    slo = 0;
    shi = n - 1;
    pair < int, int > p = query();
    
    vector < int > r;
    while (p.x){
          r.push_back(p.y + 1);
          --p.x;
          p.y = prev[p.y];
    }
    
    printf("%d\n", r.size());
    for (int i = r.size() - 1; i >= 0; --i) printf("%d ", r[i]);
    printf("\n");
    return 0;
}