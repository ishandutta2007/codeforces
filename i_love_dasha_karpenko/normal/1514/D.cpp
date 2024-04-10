#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 3E5+7;
const int BLOCK = 700;
int A[N],ans[N],cnt[N];
struct node{
    int first,second,pos;
} Q[N];
bool mc(const node &a,const node &b){
    if (a.first/BLOCK==b.first/BLOCK)
        return a.second<b.second;
    return a.first/BLOCK<b.first/BLOCK;
}
int T[N*4];
void update(int t,int tl,int tr,int pos,int val){
    if (pos<tl || pos>tr)
        return;
    if (tl==tr){
        T[t]=val;
        return;
    }
    int tm = (tl+tr)>>1;
    update(t*2+1,tl,tm,pos,val);
    update(t*2+2,tm+1,tr,pos,val);
    T[t] = max(T[t*2+1],T[t*2+2]);
}
int n,q,mx = 0,calc[N];

void upd(int pos,int val){
    --calc[cnt[pos]];
    cnt[pos]+=val;
    ++calc[cnt[pos]];
    mx = max(mx,cnt[pos]);
    while(calc[mx]==0)
        --mx;
}
int get(){
    return mx;
}
void solve(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin>>n>>q;
    for(int i = 1;i<=n;++i){
        cin>>A[i];
    }
    for(int i = 1;i<=q;++i)
        cin>>Q[i].first>>Q[i].second,Q[i].pos = i;
    sort(Q+1,Q+1+q,mc);
    int l = 1,r = 1;
    upd(A[1],1);
    for(int i = 1;i<=q;++i){
        while(l>Q[i].first){
            --l;
            upd(A[l],1);
        }
        while(r>Q[i].second){
            upd(A[r],-1);
            --r;
        }
        while(r<Q[i].second){
            ++r;
            upd(A[r],1);
        }
        while(l<Q[i].first){
            upd(A[l],-1);
            ++l;
        }
        int cnt = get();
        int len = r-l+1;
        int delta = max(0,cnt-(len-cnt)-1);
        ans[Q[i].pos] = 1+delta;
    }
    for(int i = 1;i<=q;++i)
        cout<<ans[i]<<'\n';


}
// 6: xxx xxx
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