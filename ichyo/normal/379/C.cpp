#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
typedef pair<long long, long long> P;

int main(){
    int N;
    while(cin >> N){
        vector<long long> a(N);
        REP(i, N) cin >> a[i];
        vector<P> v(N);
        REP(i, N) v[i] = P(a[i], i);
        sort(v.begin(), v.end());
        vector<long long> ans(N);
        long long last = INT_MIN;
        REP(i, N){
            long long curr = max(last + 1, v[i].first);
            ans[v[i].second] = curr;
            last = curr;
        }
        REP(i, N){
            cout << ans[i];
            if(i == N - 1) cout << endl;
            else cout << " ";
        }
    }
    return 0;
}