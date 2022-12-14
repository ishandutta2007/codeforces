#include <bits/stdc++.h>

using namespace std;

using LL = long long;
const int MOD = (int)1e9 + 7;
const int NS = (int)1e5 + 4;
int N;
int a[NS];
int cnt[NS];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; ++i){
        cin >> a[i];
        for(int x = 1; x <= a[i]; x <<= 1){
            ++cnt[i];
        }
    }
    for(int i = 1; i < N; ++i){
        if(a[i] > a[i + 1]){
            cout << 0;
            return 0;
        }
    }
    for(int i = 1; i <= N - 2; ++i){
        if(cnt[i] == cnt[i + 1] && cnt[i + 1] == cnt[i + 2]){
            cout << 1;
            return 0;
        }
    }
    int ans = MOD;
    for(int i = 1; i < N; ++i){
        int jval = 0;
        for(int j = i; j >= 1; --j){
            jval ^= a[j];
            int xval = 0;
            for(int x = i + 1; x <= N; ++x){
                xval ^= a[x];
                if(jval > xval){
                    ans = min(ans, i - j + x - i - 1);
                }
            }
        }
    }
    if(ans == MOD){
        ans = -1;
    }
    cout << ans;
    return 0;
}