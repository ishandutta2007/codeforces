#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define mp make_pair

int main() {
    
    int Q;cin>>Q;
    set<pair<int,int>> A,B;
    int q=1;
    while(Q--){
        int t;cin>>t;
        if(t==1){
            int x;cin>>x;
            A.insert(mp(q,x));
            B.insert(mp(x,-q));
            q++;
        }
        if(t==2){
            auto x=*A.begin();
            cout<<x.first<<" ";
            A.erase(x);
            B.erase(mp(x.second,-x.first));
        }
        if(t==3){
            auto x=*B.rbegin();
            cout<<-x.second<<" ";
            A.erase(mp(-x.second,x.first));
            B.erase(x);
        }
    }
    cout<<endl;
}