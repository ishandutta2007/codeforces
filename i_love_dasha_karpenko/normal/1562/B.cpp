#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 50+7;
const int MAXN = 1E6+7;
int n,A[N],simp[MAXN];
int Check(int num){
    return simp[num];
}
int solve(int pos,int left,int cur){
    if (pos==n+1){
        if (left!=0)
            return 0;
        if (Check(cur))
            return cur;
        return 0;
    }
    if (left>0){
        int r = solve(pos+1,left-1,cur*10+A[pos]);
        if (r!=0)
            return r;
    }
    int r = solve(pos+1,left,cur);
    if (r!=0)
        return r;
    return 0;
}
void solve(){
    cin>>n;
    for(int i = 1;i<=n;++i){
        char ch;
        cin>>ch;
        A[i] = ch-'0';
    }
    for(int len = 1;len<=n;++len){
        int ret = solve(1,len,0);
        if (ret){
            cout<<len<<'\n'<<ret<<endl;
            return;
        }
    }

}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    simp[1] = 1;
    for(int i = 2;i<MAXN;++i){
        if (simp[i])
            continue;
        if (ll(i)*i>MAXN)
            continue;
        for(int j = i*i;j<MAXN;j+=i)
            simp[j] = 1;
    }
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}