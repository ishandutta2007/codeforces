#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    vector<int> cnt(100001, 0);
    vector<int> output(n);
    int curr = 0;
    for(int i = n - 1; i >= 0; i--){
        if(cnt[a[i]]++ == 0){
            curr++;
        }
        output[i] = curr;
    }
    while(m--){
        int t;
        cin >> t;
        cout << output[t - 1] << endl;
    }
    return 0;
}