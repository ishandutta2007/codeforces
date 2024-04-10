#include <bits/stdc++.h>

using namespace std;

using LL = long long;
const int MOD = (int)1e9 + 7;
const int NS = (int)2004;
int N, M, k;
pair<int, int> a[NS];
int pre[NS];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> k;
    for(int i = 1; i <= M; ++i){
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + M + 1, [&](pair<int, int>&A, pair<int, int>&B){return A.first + A.second < B.first + B.second;});
    for(int i = 1; i + k - 1 <= N; ++i){
        int sum = 0;
        for(int j = 1; j <= M; ++j){
            sum += max(0, min(a[j].second, i + k - 1) - max(a[j].first, i) + 1);
            pre[j] = max(pre[j], sum);
        }
    }
    int ans = 0;
    for(int i = 1; i + k - 1 <= N; ++i){
        int sum = 0;
        for(int j = M; j >= 1; --j){
            sum += max(0, min(a[j].second, i + k - 1) - max(a[j].first, i) + 1);
            ans = max(ans, sum + pre[j - 1]);
        }
    }
    cout << ans;
    return 0;
}