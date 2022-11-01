#include <map>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
# 1 "B.cpp"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "B.cpp"
# 1 "B_global.cpp" 1
int n, m, p;
int a[400005], b[400005];
vector < int > out;
# 2 "B.cpp" 2
# 1 "B_1.cpp" 1
map < int, int > M;
int r = 0;
void add(int x){
     r -= abs(M[x]);
     ++M[x];
     r += abs(M[x]);
}
void rem(int x){
     r -= abs(M[x]);
     --M[x];
     r += abs(M[x]);
}
# 3 "B.cpp" 2
# 1 "B_load.cpp" 1
void load(){
     scanf("%d%d%d", &n, &m, &p);
     for (int i = 0; i < n; ++i) scanf("%d", a + i);
     for (int i = 0; i < m; ++i) scanf("%d", b + i);
}
# 4 "B.cpp" 2

int main(){
    load();
    for (int i = 0; i < m; ++i) add(b[i]);
    for (int q = 0; q < p; ++q){
        long long first = q, last = q + (m - 1) * (long long)p;
        if (last >= n) break;
        for (int i = first; i <= last; i += p) rem(a[i]);
        if (r == 0) out.push_back(first);
        last += p;
        while (last < n){
              add(a[first]);
              rem(a[last]);
              first += p;
              last += p;
              if (r == 0) out.push_back(first);
        }
        for (int i = first; i < last; i += p) add(a[i]);
    }
    printf("%d\n", out.size());
    sort(out.begin(), out.end());
    for (int i = 0; i < out.size(); ++i) printf("%d ", out[i] + 1);
    printf("\n");
    return 0;
}