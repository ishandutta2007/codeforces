#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int ans = (n + m - 1);
    cout << ans << endl;
    for(int j = 0; j < m; j++){
        printf("%d %d\n", 1, j + 1);
    }
    for(int i = 1; i < n; i++){
        printf("%d %d\n", i + 1, 1);
    }
    return 0;
}