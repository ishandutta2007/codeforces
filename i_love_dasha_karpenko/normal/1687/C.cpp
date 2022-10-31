#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 2e5+7;
vector<int> SG[N];
int A[N];
void solve(){

    int n,m;
    cin>>n>>m;
    for(int i = 0;i<=n;i+=1){
        SG[i].clear();
    }
    for(int i = 1;i<=n;i+=1){
        cin>>A[i];
    }
    for(int i = 1;i<=n;i+=1){
        int val; cin>>val;
        A[i] -= val;
    }
    for(int i = 1;i<=m;i+=1){
        int l,r;
        cin>>l>>r;
        SG[r].push_back(l);
    }
    int ptr = 1,start = 1;
    ll sum = 0;
    vector<int> ls,rs;
    stack<pair<int,int> > segs;
    for(int i = 1;i<=n;i+=1){
        sum += A[i];
        if (sum==0){
            if (start!=i) {
                ls.push_back(start);
                rs.push_back(i);
            }
            start = i+1;
            ptr += 1;
            for(int l:SG[i]){
                int bpos = lower_bound(rs.begin(),rs.end(),l)-rs.begin();
                if (bpos==rs.size() || ls[bpos]<l){
                    continue;
                }
                rs.resize(bpos);
                ls.resize(bpos);
            }
            while(!segs.empty() && !rs.empty() && rs.back()<=segs.top().first){
                int lim = segs.top().second;
                while(!ls.empty() && ls.back()>=lim){
                    ls.pop_back();
                    rs.pop_back();
                }
                segs.pop();
            }
        }
        else{
            for(int l:SG[i]){
                int bpos = lower_bound(rs.begin(),rs.end(),l)-rs.begin();
                if (bpos==rs.size() || ls[bpos]<l){
                    continue;
                }
                segs.push({i,l});
            }
        }

    }
    if (sum!=0 || !rs.empty()){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
    }
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