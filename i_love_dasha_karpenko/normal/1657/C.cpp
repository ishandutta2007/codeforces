#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
#define mp make_pair

void solve() {
    int n;
    cin>>n;
    deque<bool> Q(n);
    for(int i = 0;i<n;++i) {
        char ch; cin>>ch;
        Q[i] = ch==')';
    }
    int res = 0;
    while(Q.size()>1){
        if (Q[0]==1){
            int ptr = 1;
            while(ptr<Q.size() && Q[ptr]==0)
                ++ptr;
            if (ptr<Q.size()){
                while(ptr>=0){
                    Q.pop_front();
                    --ptr;
                }
                ++res;
            }
            else break;
        }
        else{
            Q.pop_front();
            Q.pop_front();
            ++res;
        }
    }
    cout<<res<<' '<<Q.size()<<endl;
}
signed main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--)
        solve();
}