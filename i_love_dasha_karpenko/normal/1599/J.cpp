//#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define all(var) var.begin(),var.end()
const int N = 1e3+7;
const int SZ = 1e6*14;
int val[SZ];
pair<int,int> ans;
int A[N],X[N],vis[N],maxind;
void solve(int need,int pos,int mask = 0,int sum = 0){
    if (pos>maxind){
        if (need!=0)
            return;
        if (val[sum])
            ans = {val[sum],mask};
        else val[sum] = mask;
        return;
    }
    solve(need-1,pos+1,(mask<<1)+1,sum+A[pos]);
    solve(need,pos+1,(mask<<1),sum);
}
void solve(){
    int n;
    cin>>n;
    maxind = min(26,n);
    int cnt[2] = {0,0};
    for(int i = 1;i<=n;++i) {
        cin >> A[i];
        cnt[A[i] & 1]++;
    }
    if (n==2){
        if (A[1]==A[2])
            cout<<"YES\n0 "<<A[1]<<endl;
        else cout<<"NO\n";
        return;
    }
    if (cnt[0]>=3 || (cnt[0] && cnt[1]>=2)){

        vector<int> V;
        if (cnt[0]>=3){
            for(int i = 1;i<=n;++i){
                if (A[i]&1)
                    continue;
                V.push_back(A[i]);
                vis[i] = 1;
                if (V.size()==3)
                    break;
            }
        }
        else{
            for(int i = 1;i<=n;++i){
                if (!(A[i]&1)) {
                    V.push_back(A[i]);
                    vis[i] = 1;
                    break;
                }
            }
            for(int i = 1;i<=n;++i){
                if (A[i]&1)
                    V.push_back(A[i]),vis[i] = 1;
                if (V.size()==3)
                    break;
            }
        }
        assert(V.size()==3);
        X[1] = (V[0]+V[2]-V[1])>>1;
        X[2] = V[0]-X[1];
        X[3] = V[2]-X[1];
        int ptr = 4;
        for(int i = 1;i<=n;++i){
            if (vis[i])
                continue;
            X[ptr++] = A[i]-X[1];
        }
        cout<<"YES\n";
        for(int i = 1;i<=n;++i)
            cout<<X[i]<<' ';
        cout<<endl;
        return;
    }
    for(int s = 1;s<=(n>>1);++s){
        solve(s,1);
        if (ans==pair<int,int>{0,0}) {
            memset(val, 0, sizeof(val));
            continue;
        }
        vector<int> V1,V2;
        for(int i = 1;i<=maxind;++i){
            if ((1<<(maxind-i))&ans.first)
                V1.push_back(A[i]),vis[i] = 1;
            if ((1<<(maxind-i))&ans.second)
                V2.push_back(A[i]),vis[i] = 1;
        }
        vector<int> V;
        for(int i = 0;i<s;++i){
            V.push_back(V1[i]);
            V.push_back(V2[i]);
        }
        X[1] = 0;
        for(int i = 2;i<=(s<<1);++i){
            X[i] = V[i-2]-X[i-1];
        }
        assert(X[1]+X[s<<1]==V[(s<<1)-1]);
        int ptr = s*2+1;
        for(int i = 1;i<=n;++i){
            if (vis[i])
                continue;
            X[ptr++] = A[i]-X[1];
        }
        cout<<"YES\n";
        for(int i = 1;i<=n;++i)
            cout<<X[i]<<' ';
        cout<<endl;
        return;
    }
    cout<<"NO\n";

}

signed main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;


    while(t--)
        solve();

}