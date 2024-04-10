
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ld eps=1e-12;
const int N=210;
const ll mod=998244353;
#define ADD(a,b) a+=b;if (a>=mod) a-=mod
#define endl '\n'
int get(int mask,int a){
    if (mask<a) return -1;
    int b=0;
    int b1=0;
    vector<int>v;
    int tot=__builtin_popcountll(mask);
    for (int i=21;i>=0;i--){
        if (mask&(1<<i)){
            v.push_back(i);
            if (b+(1<<i)<a) {
                b+=(1<<i);
                b1^=(1<<(tot-(int)v.size()));
            }
        }
    }
    reverse(v.begin(),v.end());
    b1++;
    int res=0;
    for (int i=0;i<v.size();i++){
        if (b1&(1<<i)){
            res+=(1<<v[i]);
        }
    }
    return res;
}

void solve(){
    int a,b;cin>>a>>b;

    int res=b-a;
//    cout<<get(3,1)<<endl;
    for (int mask=b;mask<=(a+b);mask++){
        if (mask+1-b>=res) break;
        int X=get(mask,a);
        res=min(res,X-a-b+1+mask);
    }

    cout<<res<<endl;


}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}

/**
5 1 1
1 4 5 2 3
2 1 3
**/