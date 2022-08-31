// luogu remote judge
#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;
class segtree{
    private:
        int sz;
        vector<int>seg;
    public:
        segtree(int _sz){
            sz=1;
            for(sz=1;sz<_sz;sz<<=1);
            seg.resize(sz<<1);
        }
        void modify(int p,int val){
            p+=sz;
            seg[p]=val;
            for(;p>1;){
                p>>=1;
                seg[p]=max(seg[p<<1],seg[p<<1|1]);
            }
        }
        int rangemax(int p,int l,int r,int s,int t){
            if(l>=t||r<=s){
                return -inf;
            }
            if(l>=s&&r<=t){
                return seg[p];
            }
            int lc=rangemax(p<<1,l,(l+r)>>1,s,t);
            int rc=rangemax(p<<1|1,(l+r)>>1,r,s,t);
            return max(lc,rc);
        }
        int rangemax(int s,int t){
            return rangemax(1,0,sz,s,t);
        }
};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    for(;T--;){
        int n;
        cin>>n;
        segtree t(n);
        vector<int>a(n),b(n);
        for(int i=0;i<n;++i){
            cin>>a[i];
            --a[i];
        }
        for(int i=0;i<n;++i){
            cin>>b[i];
            --b[i];
        }
        vector<vector<int>>g(n);
        for(int i=0;i<n;++i){
            g[a[i]].push_back(i);
            t.modify(i,a[i]);
        }
        bool ok=true;
        for(int i=n-1;i>=0;--i){
            if(g[b[i]].empty()){
                ok=false;
                break;
            }
            int pos=g[b[i]].back();
            g[b[i]].pop_back();
            if(t.rangemax(pos,n)>b[i]){
                ok=false;
                break;
            }
            t.modify(pos,0);
        }
        if(ok){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}