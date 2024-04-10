//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int N = 1E5+7;
struct node{
    int l,r;
    ll col;
};
const bool operator < (const node &a,const node &b){
    return a.l<b.l;
}
ll T[N*4],mod[N*4];
void push(int t,int tl,int tr){
    int tm = (tl+tr)>>1;
    T[t*2+1]+=mod[t]*(tm+1-tl);
    T[t*2+2]+=mod[t]*(tr-tm);
    mod[t*2+1] += mod[t];
    mod[t*2+2] += mod[t];
    mod[t] = 0;
}
void update(int t,int tl,int tr,int l,int r,int val){
    if (l>tr || tl>r)
        return;
    if (l<=tl && tr<=r){
        T[t]+=ll(tr-tl+1)*val;
        mod[t]+=val;
        return;
    }
    push(t,tl,tr);
    int tm = (tl+tr)>>1;
    update(t*2+1,tl,tm,l,r,val);
    update(t*2+2,tm+1,tr,l,r,val);
    T[t] = T[t*2+1]+T[t*2+2];
}
ll get(int t,int tl,int tr,int l,int r){
    if (l>tr || tl>r)
        return 0;
    if (l<=tl && tr<=r)
        return T[t];
    push(t,tl,tr);
    int tm = (tl+tr)/2;
    return get(t*2+1,tl,tm,l,r)+get(t*2+2,tm+1,tr,l,r);
}
void solve(){
    int n,q;
    cin>>n>>q;
    set<node> S;
    for(int i = 1;i<=n;++i)
        S.insert({i,i,i});
    while(q--){
        int type;
        cin>>type;
        if (type==1){
            int l,r;
            ll val;
            cin>>l>>r>>val;
            auto it = S.upper_bound({l,0,0});
            it = prev(it);
            if (it->l!=l){
                node val = *it;
                S.erase(it);
                S.insert({val.l,l-1,val.col});
                S.insert({l,val.r,val.col});
                it = S.upper_bound({l,0,0});
                it = prev(it);
            }

            while(it!=S.end()){
                if (it->r>=r)
                    break;

                update(0,1,n,it->l,it->r,abs(val-it->col));
                auto was = it;
                it = next(it);
                S.erase(was);
            }
            if (it->r!=r){
                node val = *it;
                S.erase(it);
                S.insert({val.l,r,val.col});
                S.insert({r+1,val.r,val.col});
                it = S.upper_bound({r,0,0});
                it = prev(it);
            }

            update(0,1,n,it->l,it->r,abs(val-it->col));
            S.erase(it);
            S.insert({l,r,val});

        }
        else{
            int l,r;
            cin>>l>>r;
            cout<<get(0,1,n,l,r)<<endl;
        }
//        cout<<"         "<<S.size()<<endl;
    }

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