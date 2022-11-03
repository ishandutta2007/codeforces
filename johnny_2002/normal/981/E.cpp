#include <bits/stdc++.h>

using namespace std;


typedef long long ll;

const int N=1e4+10;
int n;
bitset<N> s[20],ans;
vector <int> v[N<<2];
void add_seg(int node,int L,int R,int l,int r,int val){
        if (L>r||R<l) return;
        if (l<=L&&R<=r) {
                v[node].push_back(val);
                return;
        }
        add_seg(node*2,L,(L+R)/2,l,r,val);
        add_seg(node*2+1,(L+R)/2+1,R,l,r,val);
}
void DP(int depth,int node,int L,int R){
        s[depth]=s[depth-1];
        for(auto val:v[node]) s[depth]=s[depth]|(s[depth]<<val);
        if (L==R){
                ans=ans|s[depth];
                return;
        }
        DP(depth+1,node*2,L,(L+R)/2);
        DP(depth+1,node*2+1,(L+R)/2+1,R);
}
int main(){
        int test;
        cin>>n>>test;
        while (test--){
                int L,R,val;
                cin>>L>>R>>val;
                add_seg(1,1,n,L,R,val);
        }
        s[0][0]=1;
        DP(1,1,1,n);
        int nans=0;
        for(int i=1;i<=n;i++) if (ans[i]==1) nans++;
        cout<<nans<<'\n';
        for(int i=1;i<=n;i++) if (ans[i]==1) cout<<i<<" ";
}