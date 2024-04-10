//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int MX = 3E5;
struct tree{
    ll T[MX*4];
    void update(int t,int tl,int tr,int pos,int val){
        if (tl>pos || tr<pos)
            return;
        if (tl==tr){
            T[t]+=val;
            return;
        }
        int tm = (tl+tr)/2;
        update(t*2+1,tl,tm,pos,val);
        update(t*2+2,tm+1,tr,pos,val);
        T[t] = T[t*2+1]+T[t*2+2];
    }
    ll query(int t,int tl,int tr,int l,int r){
        if (tl>r || l>tr)
            return 0;
        if (l<=tl && tr<=r)
            return T[t];
        int tm = (tl+tr)/2;
        return query(t*2+1,tl,tm,l,r)+query(t*2+2,tm+1,tr,l,r);
    }
    ll get(int l,int r){
        return query(0,1,MX,l,r);
    }
    void upd(int pos,ll val){
        update(0,1,MX,pos,val);
    }
};
tree prefix_dif,cnt,sum;
void solve(){
    int n;
    cin>>n;
    ll res = 0;
    for(int i = 1;i<=n;++i){
        int cur;
        cin>>cur;
        res+=(i-1-cnt.get(1,cur))*cur; // cur to suf
        res+=cnt.get(1,cur)*cur-prefix_dif.get(1,cur); // pref to cur
        res+=sum.get(1,cur); // cur to pref

        for(int mult = 1;mult*cur<=MX;++mult){
            ll num = mult*cur;
            ll nxt = min(MX,(mult+1)*cur-1);
            res+=sum.get(num,nxt)-cnt.get(num,nxt)*num;
            prefix_dif.upd(num,cur);
        }
        cnt.upd(cur,1);
        sum.upd(cur,cur);
        cout<<res<<' ';
    }
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int t;
    t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}