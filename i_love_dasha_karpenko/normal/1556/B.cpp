#pragma GCC Optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 1e5+7;
int A[N];
void solve(){
    int n;
    cin>>n;
    vector<int> V[2];
    int cnt[] = {0,0};
    for(int i = 1;i<=n;++i){
        cin>>A[i];
        A[i]&=1;
        V[A[i]].push_back(i);
        cnt[A[i]]++;
    }
    if (abs(cnt[0]-cnt[1])>1){
        cout<<"-1\n";
        return;
    }
    ll res = 0;
    if (cnt[0]>cnt[1]){
        for(int i = 0;i<V[0].size();++i){
            res+=abs(i*2+1-V[0][i]);
        }
        for(int i = 0;i<V[1].size();++i){
            res+=abs((i+1)*2-V[1][i]);
        }
    }
    else if (cnt[1]>cnt[0]){
        for(int i = 0;i<V[1].size();++i){
            res+=abs(i*2+1-V[1][i]);
        }
        for(int i = 0;i<V[0].size();++i){
            res+=abs((i+1)*2-V[0][i]);
        }
    }
    else{
        for(int i = 0;i<V[0].size();++i){
            res+=abs(i*2+1-V[0][i]);
        }
        for(int i = 0;i<V[1].size();++i){
            res+=abs((i+1)*2-V[1][i]);
        }
        ll r = res;
        res = 0;
        swap(V[0],V[1]);
        for(int i = 0;i<V[0].size();++i){
            res+=abs(i*2+1-V[0][i]);
        }
        for(int i = 0;i<V[1].size();++i){
            res+=abs((i+1)*2-V[1][i]);
        }
        res = min(res,r);
    }
    cout<<res/2<<endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin>>t;
    //t = 1;
    while(t--)
        solve();
    return 0;
}