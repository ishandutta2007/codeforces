#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int m, n;
vector < int > v1, v2;

int main(){
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; ++i){
        int a;
        scanf("%d", &a);
        v1.push_back(a);
    }
    for (int i = 0; i < n; ++i){
        int a;
        scanf("%d", &a);
        v2.push_back(a);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    if (v1.back() < v2.back()){swap(m, n); swap(v1, v2);}
    long long r = 0, r2 = 0;
    for (int i = 0; i < n; ++i) r2 += v2[i];
    r += r2;
    for (int i = 0; i < m - 1; ++i){
        long long cr1, cr2, cr3;
        cr1 = v1[i];
        cr2 = (long long)n * v1[i];
        cr3 = r2;
        r += min(cr1, cr3);
    }
    printf("%I64d\n", r);
    return 0;
}