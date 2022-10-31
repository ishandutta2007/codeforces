//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int DIM = 2E5+7;
int cnt[DIM],res = 0;
void add(int pos,int val){
    res+=(cnt[pos]!=0);
    cnt[pos]+=val;
    res-=(cnt[pos]!=0);
}
void solve(){
    int n,m;
    cin>>n>>m;
    res = n;
    for(int i = 1;i<=m;++i){
        int u,v;
        cin>>u>>v;
        if (u>v)
            swap(u,v);
        add(u,1);
    }
    int q;
    cin>>q;
    for(int i = 1;i<=q;++i){
        int type;
        cin>>type;
        if (type==1){
            int u,v;
            cin>>u>>v;
            if (u>v)
                swap(u,v);
            add(u,1);
        }
        if (type==2){
            int u,v;
            cin>>u>>v;
            if (u>v)
                swap(u,v);
            add(u,-1);
        }
        if (type==3){
            cout<<res<<endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    t = 1;
    while(t--)
        solve();
    return 0;
}