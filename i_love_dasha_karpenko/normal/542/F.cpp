#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll>pairll;

#define fr first
#define sc second
#define pb push_back
#define pf push_front

ll n,t,a[1007],b[1007],f[107];

priority_queue<ll>q[107],q1[107];

ll S(ll x){
    ll res=0;
    if(x==1){
        if(q[x].size()>0){
            res=q[x].top();
            q[x].pop();
            return res;
        }else{
            f[x]=1;
            return 0;
        }
    }
    if(q[x].size()==0){
        if(f[x]==1)return 0;
        else {
            res+=S(x-1);
            res+=S(x-1);
        }
        if (res==0)
            f[x] = 1;
        return res;
    }
    ll l=S(x-1);
    ll r=S(x-1);
    if(l+r<=q[x].top()){
        if(l>0)q[x-1].push(l);
        if(r>0)q[x-1].push(r);
        res=q[x].top();
        q[x].pop();
        return res;
    }
    return l+r;
}

int main() {

    cin>>n>>t;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        q[a[i]].push(b[i]);
    }
    cout<<S(t)<<endl;

    return 0;

}