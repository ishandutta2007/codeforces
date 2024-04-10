#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 107;
const int AL = 26;
int cnt[2][AL];
char gc(int code){
    return char('a'+code);
}
void solve(){
    int n,m,k;
    cin>>n>>m>>k;

    for(int i = 0;i<2;i+=1){
        for(int j = 0;j<AL;j+=1){
            cnt[i][j] = 0;
        }
        string s;
        cin>>s;
        for(char to:s){
            cnt[i][to-'a'] += 1;
        }
    }
    string ans = "";
    int ptr[2] = {0,0};
    int len[2] = {0,0};
    while(1){
        bool flag = 0;
        for(int i = 0;i<2;i+=1){
            while(ptr[i]<AL && cnt[i][ptr[i]]==0){
                ptr[i] += 1;
            }
            if (ptr[i]>=AL){
                flag = 1;
                break;
            }
        }
        if (flag){
            break;
        }
        if (len[0]!=k && (ptr[0]<ptr[1] || len[1]==k)){
            ans += gc(ptr[0]);
            cnt[0][ptr[0]] -= 1;
            len[0] += 1;
            len[1] = 0;
        }
        else if (ptr[1]<ptr[0] || len[0]==k){
            ans += gc(ptr[1]);
            cnt[1][ptr[1]] -= 1;
            len[1] += 1;
            len[0] = 0;
        }
        else{
            assert(0);
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}