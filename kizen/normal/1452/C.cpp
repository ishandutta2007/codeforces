#include <bits/stdc++.h>

using namespace std;

using LL = long long;
const int MOD = (int)1e9 + 7;
const int NS = (int)2e5 + 4;
int N, T;
char s[NS];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while(T--){
        cin >> (s + 1);
        N = strlen(s + 1);
        int ans = 0;
        int cnt = 0;
        for(int i = 1; i <= N; ++i){
            if(s[i] == '('){
                ++cnt;
            }
            if(s[i] == ')' && cnt){
                --cnt; ++ans;
            }
        }
        cnt = 0;
        for(int i = 1; i <= N; ++i){
            if(s[i] == '['){
                ++cnt;
            }
            if(s[i] == ']' && cnt){
                --cnt; ++ans;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}