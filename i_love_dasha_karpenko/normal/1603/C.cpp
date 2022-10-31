#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define all(var) var.begin(),var.end()
const int N = 1e5+7;
const int INF = 1e9;
const int MOD = 998244353;
int A[N];
int up(int a,int b){
    return a/b+(a%b!=0);
}
void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;++i){
        cin>>A[i];
    }
    vector<pair<int,int> > prev;
    vector<pair<int,int> > cur;
    int res = 0;
    for(int i = n;i>=1;--i){

        int sz = prev.size();
        int cnt = 1;
        for(int j = 0;j<sz;++j){
            if (prev[j].first>=A[i]){
                int sum = prev[j].second;
                while(++j<sz){
                    sum+=prev[j].second;
                    if (sum>=MOD)
                        sum-=MOD;
                }
                cnt+=sum;
                if (cnt>=MOD)
                    cnt-=MOD;
                break;
            }
            int ptr = j;
            int sum = prev[j].second;
            while(ptr+1<sz && up(A[i],prev[ptr+1].first)==up(A[i],prev[j].first)) {
                ++ptr;
                sum += prev[ptr].second;
            }
            if (sum>=MOD)
                sum-=MOD;
           res+=ll(sum)*(up(A[i],prev[j].first)-1)%MOD*i%MOD;
           if (res>=MOD){
               res-=MOD;
            }
            cur.push_back({A[i]/up(A[i],prev[j].first),sum});
           j = ptr;
        }
        //reverse(all(cur));
        cur.push_back({A[i],cnt});
        swap(cur,prev);
        cur.clear();
    }
    cout<<res<<endl;

}

signed main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin>>t;

    while(t--)
        solve();

}