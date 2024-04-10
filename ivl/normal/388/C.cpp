#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main(){
    scanf("%d", &n);
    int r1 = 0, r2 = 0;
    vector < int > v;
    for (int i = 0; i < n; ++i){
        int x, y;
        scanf("%d", &x);
        for (int j = 0; j < x; ++j){
            int z;
            scanf("%d", &z);
            if (j * 2 + 1 < x) r1 += z;
            if (j * 2 + 1 == x) v.push_back(z);
            if (j * 2 + 1 > x) r2 += z;
        }
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i){
        if (i & 1) r2 += v[i];
        else r1 += v[i];
    }
    printf("%d %d\n", r1, r2);
    return 0;
}