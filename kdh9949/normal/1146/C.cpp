#include <bits/stdc++.h>
using namespace std;

int main(){
    int tc; scanf("%d", &tc); while(tc--){
        int n;
        scanf("%d", &n);
        int ans = 0;
        for(int i = 0; i < 9; i++){
            vector<int> v, w;
            for(int j = 1; j <= n; j++){
                if((j >> i) & 1) v.push_back(j);
                else w.push_back(j);
            }
            if(!v.size() || !w.size()) continue;
            printf("%d %d ", v.size(), w.size());
            for(int j : v) printf("%d ", j);
            for(int j : w) printf("%d ", j);
            puts("");
            fflush(stdout);
            int x; scanf("%d", &x);
            ans = max(ans, x);
        }
        printf("-1 %d\n", ans);
        fflush(stdout);
    }
}