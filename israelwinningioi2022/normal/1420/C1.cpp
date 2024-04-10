#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18;

struct Val{
    int mne=0, mno=INF, mxe=0, mxo=-INF;
};
struct SEG{
    int sz;
    vector<Val> a;
    SEG(int n){
        for(sz=1;sz<n;sz*=2);
        a.resize(2*sz);
    }
    void update(int i, int x){
        i+=sz;
        a[i] = {0,x,0,x};
        for(i/=2; i; i/=2){
            a[i].mne = min(a[2*i].mne + a[2*i+1].mne, a[2*i].mno - a[2*i+1].mxo);
            a[i].mno = min(a[2*i].mne + a[2*i+1].mno, a[2*i].mno - a[2*i+1].mxe);
            a[i].mxe = max(a[2*i].mxe + a[2*i+1].mxe, a[2*i].mxo - a[2*i+1].mno);
            a[i].mxo = max(a[2*i].mxe + a[2*i+1].mxo, a[2*i].mxo - a[2*i+1].mne);
        }
    }
    int query(){
        return max(a[1].mxe, a[1].mxo);
    }
};


int solve(){
    int n,q; cin>>n>>q;
    vi a(n); loop(i,0,n) cin>>a[i];
    SEG seg(n);
    loop(i,0,n) seg.update(i,a[i]);
    cout<<seg.query()<<endl;
    loop(i,0,q){
        int x,y; cin>>x>>y; x--; y--;
        swap(a[x], a[y]);
        seg.update(x, a[x]);
        seg.update(y, a[y]);
        cout<<seg.query()<<endl;
    }
    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    loop(i,0,t) solve();
    return 0;
}
/*
color a
cls
g++ b.cpp -o a & a
3
3 1
1 3 2
1 2
2 2
1 2
1 2
1 2
7 5
1 2 5 4 3 6 7
1 2
6 7
3 4
1 2
2 3

*/