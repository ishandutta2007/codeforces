#include <bits/stdc++.h>
using namespace std;
struct tpl {
    long long x,t,ind;
    //t==1 query
    //t==-1 update
    bool operator < (const tpl &e1) const {
        if (x==e1.x) return t>e1.t;
        return x<e1.x;
    }
};
struct in {
    long long l,r,c;
};
const long long MX=8*1e9+100;
long long n,x,p1,p2,p3,ans=MX;
in arr[300000];
vector<tpl> lin;
long long ele[300000];
int main() {
    cin>>n>>x;
    for (long long i=0; i<n; i++) {
        cin>>p1>>p2>>p3;
        arr[i]={p1,p2,p3};
        lin.push_back({p1,1,i});
        lin.push_back({p2,-1,i});
    }
    for (long long i=0; i<290000; i++) ele[i]=MX;
    sort(lin.begin(),lin.end());
    for (long long i=0; i<lin.size(); i++) {
        long long ind=lin[i].ind;
        long long len=arr[ind].r-arr[ind].l+1;
        if (lin[i].t==-1) {
            ele[len]=min(ele[len],arr[ind].c);
        }
        else if (lin[i].t==1) {
            if (len>x) continue;
            ans=min(ans,arr[ind].c+ele[x-len]);
        }
    }
    if (ans>=MX) cout<<-1<<'\n';
    else cout<<ans<<'\n';
}