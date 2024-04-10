#include <cstdio>
#include <vector>

using namespace std;

class klasa{
      public:
      long long lo;
      int type, val;
      klasa(long long a = 0, /*long long b = 0,*/ int c = 0, int d = 0){
                lo = a;
                //hi = b;
                type = c;
                val = d;
      }
};

int m;

long long sz;
vector < klasa > V;

long long ask(long long x, int lo = 0, int hi = V.size() - 1){
     int mid = (lo + hi + 1) >> 1;
     while (lo != hi){
           if (V[mid].lo > x) hi = mid - 1;
           else lo = mid;
           mid = (lo + hi + 1) >> 1;
     }
     if (V[lo].type == 1) return V[lo].val;
     return ask((x - V[lo].lo) % V[lo].val);
}

int main(){
    scanf("%d", &m);
    for (int i = 0; i < m; ++i){
        long long t;
        scanf("%I64d", &t);
        if (t == 1){
           long long x;
           scanf("%I64d", &x);
           V.push_back(klasa(sz, /*sz,*/ 1, x));
           ++sz;
        }
        else {
             long long x, y;
             scanf("%I64d%I64d", &x, &y);
             V.push_back(klasa(sz, /*sz + x * y - 1,*/ 2, x));
             sz += x * y;
        }
    }
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        long long x;
        scanf("%I64d", &x);
        printf("%I64d ", ask(x - 1));
    }
    return 0;
}