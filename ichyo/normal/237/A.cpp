#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int main(){
    int n;
    cin >> n;
    int ans = 0;
    map<int, int> cnt;
    for(int i = 0; i < n; i++){
        int h, m;
        cin >> h >> m;
        int t = h * 60 + m;
        cnt[t] += 1;
        ans = max(ans, cnt[t]);
    }
    cout << ans << endl;
    return 0;
}