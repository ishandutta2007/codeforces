#include <cstdio>
#include <vector>
#define x first
#define y second

using namespace std;

long long gcd(long long a, long long b){
     if (b) return gcd(b, a % b);
     return a;
}

const long long oo = 1000000000000LL;

long long V(long long a, long long b){
     return gcd(a, b);
     if (a == b) return a;
     if (b == 0) return a;
     if (a == 0) return b;
     if (a >= oo || b >= oo) return oo;
     long long r = a * b / gcd(a, b);
     if (r > oo) return oo;
     return r;
}

long long tur[1 << 18];
void set(int pos, long long val, int cp = 1, int lo = 0, int hi = (1 << 17) - 1){
     if (lo > pos || hi < pos) return;
     if (lo == hi){tur[cp] = val; return;}
     set(pos, val, cp * 2, lo, (lo + hi) / 2);
     set(pos, val, cp * 2 + 1, (lo + hi + 1) / 2, hi);
     tur[cp] = V(tur[cp * 2], tur[cp * 2 + 1]);
}
int slo, shi;
long long query(int cp = 1, int lo = 0, int hi = (1 << 17) - 1){
     if (lo > shi || hi < slo) return 0;
     if (lo >= slo && hi <= shi) return tur[cp];
     return V(
            query(cp * 2, lo, (lo + hi) / 2),
            query(cp * 2 + 1, (lo + hi + 1) / 2, hi));
}

pair < long long, int > t2[1 << 18];
void set2(int pos, long long val, int cp = 1, int lo = 0, int hi = (1 << 17) - 1){
     if (lo > pos || hi < pos) return;
     if (lo == hi){t2[cp] = make_pair(val, 1); return;}
     set2(pos, val, cp * 2, lo, (lo + hi) / 2);
     set2(pos, val, cp * 2 + 1, (lo + hi + 1) / 2, hi);
     pair < long long, int > p1 = t2[cp * 2], p2 = t2[cp * 2 + 1];
     if (p1.x == p2.x) p1.y += p2.y;
     else p1 = min(p1, p2);
     t2[cp] = p1;
}
pair < long long, int > query2(int cp = 1, int lo = 0, int hi = (1 << 17) - 1){
     if (lo > shi || hi < slo) return make_pair(1000000005, 0);
     //printf(" --- %d %d %d [%I64d]\n", cp, lo, hi, t2[cp].x);
     if (lo >= slo && hi <= shi) return t2[cp];
     pair < long long, int > p1 = query2(cp * 2, lo, (lo + hi) / 2), p2 = query2(cp * 2 + 1, (lo + hi + 1) / 2, hi);
     if (p1.x == p2.x) p1.y += p2.y;
     else p1 = min(p1, p2);
     //printf("%d %d %d --- %I64d\n", cp, lo, hi, p1.x);
     return p1;
}

int n;
long long s[100005];
int t;

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        scanf("%I64d", s + i);
        set(i, s[i]);
        set2(i, s[i]);
    }
    scanf("%d", &t);
    for (int i = 0; i < t; ++i){
        int l, r;
        scanf("%d%d", &l, &r);
        --l; --r;
        slo = l;
        shi = r;
        long long v = query();
        //printf("1 pass\n");
        pair < long long, int > p = query2();
        //printf("2 pass\n");
        //printf("3 %I64d\n", p.x);
        if (v % p.x) printf("%d\n", r - l + 1);
        else printf("%d\n", r - l + 1 - p.y);
    }
    return 0;
}