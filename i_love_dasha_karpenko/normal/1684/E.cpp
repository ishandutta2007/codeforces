#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 2e5+7;
bool vis[N];
pair<int,int> T[N*2];
pair<int,int> merge(pair<int,int> a,pair<int,int> b){
    a.first += b.first;
    a.second += b.second;
    return a;
}
void update(int t,int tl,int tr,int pos,pair<int,int> val){
    if (tl>pos || tr<pos){
        return;
    }
    if (tl==tr){
        T[t].first += val.first;
        T[t].second += val.second;
        return;
    }
    int tm = (tl+tr)/2;
    update(t+1,tl,tm,pos,val);
    update(t+(tm-tl+1)*2,tm+1,tr,pos,val);
    T[t] = merge(T[t+1],T[t+(tm-tl+1)*2]);
}
vector<pair<int,int> > cnt;
void get(int t,int tl,int tr,int &need,int &got){
    if (need==0){
        return;
    }
    if (T[t].first<need){
        need -= T[t].first;
        got += T[t].second;
        return;
    }
    if (tl==tr){
        if (T[t].first==need){
            got += 1;
        }
        need = 0;
        return;
    }
    int tm = (tl+tr)/2;
    get(t+1,tl,tm,need,got);
    get(t+(tm-tl+1)*2,tm+1,tr,need,got);
}
void solve(){
    int n,k;
    cin>>n>>k;
    map<int,int> M;
    for(int i = 0;i<=n;i+=1){
        vis[i] = 0;
    }
    for(int i = 1;i<=n;i+=1){
        int val; cin>>val;
        M[val] += 1;
        if (val<n){
            vis[val] = 1;
        }
    }

    vector<int> vl;
    cnt.clear();
    for(auto [val,qnt]:M){
        vl.push_back(val);
        cnt.push_back({qnt,val});
    }
    map<int,int> t_pos;
    sort(cnt.begin(),cnt.end());
    for(int i = 0;i<M.size();i+=1){
        t_pos[cnt[i].second] = i;
    }
    int ptr = int(vl.size())-1;
    int base = 0;
    for(int i = 0;i<n;i+=1){
        base += vis[i];
    }
    int cm = 0;
    while(vis[cm]){
        cm += 1;
    }
    int res = int(M.size()) - cm;
    for(int i = 0;i<=n*2;i+=1){
        T[i] = {0,0};
    }
    for(int mx = n;mx>=0;mx-=1){
        base -= vis[mx];
        while(ptr>=0 && vl[ptr]>=mx){
            update(0,0,n-1,t_pos[vl[ptr]],{M[vl[ptr]],1});
            ptr -= 1;
        }
        if (mx-base>k){
            continue;
        }
        int need = k;
        int got = 0;
        get(0,0,n-1,need,got);
        res = min(res,int(M.size())-got-mx+(mx-base));
    }
    cout<<res<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}