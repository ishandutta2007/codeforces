#include <bits/stdc++.h>
using namespace std;

int n, k;
pair<int,int> t[105];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &t[i].first, &t[i].second);
    }
    scanf("%d", &k);

    for(int i = 0; i < n; i++){
        if(t[i].first <= k and t[i].second >= k) printf("%d\n", n - i);
    }
    return 0;
}