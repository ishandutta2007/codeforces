//#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 1e5+7;
pair<int,int> A[N];
ll res = 0;
void solve(int n,int l,int wmax){
    vector<int> V1,V2;
    for(int i = 1;i<=n;++i){
        if (A[i].second==1)
            V1.push_back(A[i].first);
        else V2.push_back(A[i].first);
    }
    sort(V1.begin(),V1.end());
    sort(V2.begin(),V2.end());
    for(auto to:V1){
        int tl = 0,tr = V2.size();
        while(tl!=tr){
            int tm = (tl+tr)>>1;
            int tt = V2[tm];
            int mid = tt+to+l;
            int t = tt-to+l;
            if (t>0 && ll(wmax)*t>abs(mid))
                tr = tm;
            else tl = tm+1;
        }
        res+=V2.size()-tr;
    }
    cout<<res<<endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,l,wmax;
    cin>>n>>l>>wmax;
    for(int i = 1;i<=n;++i){
        cin>>A[i].first>>A[i].second;
    }
    solve(n,l,wmax);
    return 0;
}