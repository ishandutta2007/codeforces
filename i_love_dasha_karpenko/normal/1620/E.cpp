#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
//#define int ll
#define all(var) var.begin(),var.end()
#define mp make_pair
#define gi() int(x-'0')

const int N = 1e6+7;
vector<int> in_col[N];
int col_of[N],cur[N],A[N];
void solve() {
    int q;
    cin>>q;
    int ptr = 0;
    int n = 0;
    while(q--){
        int type;
        cin>>type;
        if (type==1){
            int val;
            cin>>val;
            if (cur[val]==0)
                cur[val] = ++ptr,col_of[ptr] = val;
            val = cur[val];
            in_col[val].push_back(++n);
        }
        if (type==2){
            int x,y;
            cin>>x>>y;
            if (x==y)
                continue;
            if (cur[y]==0){
                if (cur[x]!=0){
                    cur[y] = cur[x];
                    col_of[cur[y]] = y;
                    cur[x] = 0;
                }
            }
            else if (cur[x]){
                if (in_col[cur[x]].size()>in_col[cur[y]].size()){
                    swap(in_col[cur[x]],in_col[cur[y]]);
                }
                for(int to:in_col[cur[x]])
                    in_col[cur[y]].push_back(to);
                in_col[cur[x]].clear();
                cur[x] = 0;
            }
        }
    }
    for(int i = 1;i<=ptr;++i)
        for(int pos:in_col[i])
            A[pos] = col_of[i];
    for(int i = 1;i<=n;++i)
        cout<<A[i]<<' ';
    cout<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //+cin>>t;

    while(t--)
        solve();
}