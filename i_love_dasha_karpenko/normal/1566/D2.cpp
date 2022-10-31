#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 300+7;
pair<int,int> A[N*N];
int n,m;

int T[N][N];

void add(int t,int pos,int delta){
    for(int i = pos;i<=m;i+=(i&-i))
        T[t][i]+=delta;
}
int get(int t,int pos){
    int ret = 0;
    for(int i = pos;i>0;i-=(i&-i))
        ret+=T[t][i];
    return ret;
}
void solve(){

    cin>>n>>m;
    map<int,vector<int> > M;
    for(int i = 1;i<=n*m;++i){
        cin>>A[i].first;
        A[i].second = i;
        M[A[i].first].push_back(A[i].second);
    }
    int ptr = 0;
    for(auto [val,V]:M){
        vector<int> R;
        for(auto pos:V){
            ++ptr;
            if (ptr%m==1){
                int cur = ptr-1;
                for(int to:R){
                    A[cur].second = to;
                    --cur;
                }
                R.clear();
            }
            R.push_back(pos);
        }
        int cur = ptr;
        for(int to:R){
            A[cur].second = to;
            --cur;
        }
        R.clear();
    }
    for(int i = 1;i<=n*m;++i){
        A[i].first = i;
        swap(A[i].first,A[i].second);
    }
    sort(A+1,A+1+n*m);
    ll res = 0;
    for(int i = 1;i<=n*m;++i){
        int row = A[i].second/m-(A[i].second%m==0);
        int col = A[i].second-row*m;
        ++row;
        res+=get(row,col);
        add(row,col,1);
    }
    cout<<res<<endl;
    for(int i = 0;i<=n;++i){
        for(int j = 0;j<=m;++j){
            T[i][j] = 0;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}