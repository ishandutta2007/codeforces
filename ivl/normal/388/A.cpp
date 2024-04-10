#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int oo = 1000000005;

int n;
int in[105];

bool check(int x){
     vector < int > v(x, oo);
     int p = 0;
     for (int i = 0; i < n; ++i){
         if (v.size() == 0) return false;
         if (v[p] == 0){
            v.erase(v.begin() + p);
            if (p == v.size()) p = 0;
            --i;
            continue;
         }
         v[p] = min(v[p] - 1, in[i]);
         ++p;
         if (p == v.size()) p = 0;
     }
     return true;
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", in + i);
    sort(in, in + n);
    reverse(in, in + n);
    int lo = 0, hi = n, mid = (lo + hi) >> 1;
    while (lo != hi){
          if (check(mid)) hi = mid;
          else lo = mid + 1;
          mid = (lo + hi) >> 1;
    }
    printf("%d\n", lo);
    return 0;
}