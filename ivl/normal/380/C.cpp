#include <cstdio>
#include <algorithm>

using namespace std;

class tur{
      public:
      int left, right, mat;
      tur(int a = 0, int b = 0, int c = 0){
              left = a;
              right = b;
              mat = c;
      }
      tur operator=(tur x){
          left = x.left;
          right = x.right;
          mat = x.mat;
          return x;
      }
      tur operator+(tur x){
          tur r;
          r.mat = mat + x.mat;
          r.left = left;
          r.right = x.right;
          int y = min(right, x.left);
          r.mat += y;
          r.left += x.left - y;
          r.right += right - y;
          return r;
      }
};

char in[2000005];

tur tt[1 << 21];
void init(int pos = 1, int lo = 0, int hi = (1 << 20) - 1){
     if (lo == hi){
        if (in[lo] == ')') ++tt[pos].left;
        else ++tt[pos].right;
        return;
     }
     init(pos * 2, lo, (lo + hi) >> 1);
     init(pos * 2 + 1, (lo + hi + 1) >> 1, hi);
     tt[pos] = (tt[pos * 2] + tt[pos * 2 + 1]);
}

int slo, shi;
tur fake;
tur calc(int pos = 1, int lo = 0, int hi = (1 << 20) - 1){
    if (lo > shi || hi < slo) return fake;
    if (lo >= slo && hi <= shi) return tt[pos];
    return calc(pos * 2, lo, (lo + hi) >> 1) + calc(pos * 2 + 1, (lo + hi + 1) >> 1, hi);
}

int main(){
    scanf("%s", in);
    init();
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i){
        int a, b;
        scanf("%d%d", &a, &b);
        --a; --b;
        slo = a;
        shi = b;
        printf("%d\n", calc().mat * 2);
    }
    return 0;
}