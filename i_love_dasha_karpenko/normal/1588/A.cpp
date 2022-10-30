//#pragma GCC optimize ("Ofast")
//#pragma GCC target ("avx2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define all(var) var.begin(),var.end()
#define gi(x) int(x-'0')
#define mp make_pair
#define gdb cout<<"dolboeb"<<endl;
const int N = 107;
const int NUM = 107;
int B[N],cnt[2][NUM*2],need[NUM*2];
void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;++i){
        int num;
        cin>>num;
        cnt[0][num+NUM]++;
    }
    for(int i = 1;i<=n;++i){
        int num;
        cin>>num;
        ++need[NUM+num];
    }
    int flag = 0;
    for(int num = 0;num+1<NUM*2;++num){
        int g = min(cnt[1][num],need[num]);
        need[num]-=g;
        cnt[1][num]-=g;
        g = min(need[num],cnt[0][num]);
        need[num]-=g;
        cnt[0][num]-=g;
        cnt[1][num+1]+=cnt[0][num];
        cnt[0][num] = 0;
        if (need[num]){
            flag = 1;
            break;
        }
    }
    if (flag)
        cout<<"NO\n";
    else cout<<"YES\n";
    memset(cnt,0,sizeof(cnt));
    memset(need,0,sizeof(need));
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}