#include <bits/stdc++.h>

using namespace std;

using LL = long long;
const int MOD = (int)1e9 + 7;
const int NS = (int)1e6 + 4;
int T, N, k;
char a[NS], b[NS];
int cnt[30][3];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while(T--){
        cin >> N >> k;
        cin >> (a + 1) >> (b + 1);
        memset(cnt, 0, sizeof(cnt));
        for(int i = 1; i <= N; ++i){
            ++cnt[a[i] - 'a' + 1][1];
            ++cnt[b[i] - 'a' + 1][2];
        }
        for(int i = 1; i <= 25; ++i){
            if(cnt[i][1] > cnt[i][2]){
                int mov = (cnt[i][1] - cnt[i][2]) / k + ((cnt[i][1] - cnt[i][2]) % k > 0);
                if(cnt[i][1] - mov * k < 0){
                    ++mov;
                }
                cnt[i][1] -= mov * k, cnt[i + 1][1] += mov * k;
            }
        }
        int f = 1;
        for(int i = 1; i <= 26; ++i){
            if(cnt[i][1] != cnt[i][2]){
                f = 0;
                break;
            }
        }
        if(f){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
    return 0;
}