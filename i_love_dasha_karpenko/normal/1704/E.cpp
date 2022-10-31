//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 big;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
#define int ll
const int N = 1e3+7;
const ll MOD =  998244353;
vector<int> G[N];
big A[N],B[N],in[N];
bool del[N];
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i+=1){
        del[i] = 0;ll val;
        cin>>val;
        A[i] = val;
        G[i].clear();
        in[i] = 0;

    }
    for(int i = 1;i<=m;i+=1){
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        in[y] += 1;

    }
    ll res = 0;
    for(int st = 1;st<=max(n,m);st+=1){
        bool flag = 0;
        for(int i = 1;i<=n;i+=1){
            if (A[i]){
                flag = 1;
            }
        }
        if (!flag){
            break;
        }
        for(int i = 1;i<=n;i+=1){
            B[i] = A[i];
        }
        for(int i = 1;i<=n;i+=1){
            if (A[i]){
                B[i] -= 1;
                for(int to:G[i]){
                    B[to] += 1;
                }
            }
        }
        for(int i = 1;i<=n;i+=1){
            A[i] = B[i];
        }
        res += 1;

    }
//    for(int i = 1;i<=n;i+=1){
//        cout<<A[i]<<' ';
//    }
//    cout<<endl;

    while(1){
        while(1){
            bool flag = 0;
            for(int i = 1;i<=n;i+=1){
                if (A[i]==0 && in[i]==0 && !del[i]){
                    del[i] = 1;
                    for(int to:G[i]){
                        in[to] -= 1;
                    }
                    flag = 1;
                }
            }
            if (!flag){
                break;
            }
        }
        int pos = -1;
        for(int i = 1;i<=n;i+=1){
            if (!del[i] && in[i]==0 && (pos==-1 || A[i]<A[pos])){
                pos = i;
                break;
            }
        }
        //cout<<"GDB "<<pos<<' '<<A[pos]<<' '<<res<<' '<<endl;
        if (pos==-1){
            break;
        }
        res = (res+A[pos])%MOD;
        big chg = A[pos];
        //cout<<ll(chg)<<endl;
        for(int i = 1;i<=n;i+=1){
            if (!del[i]){
                A[i] = A[i] + (in[i]-1)*chg + (A[i]==0);
            }
           // cout<<ll(in[i])<<' ';
        }
       // cout<<endl;

    }
    cout<<res<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}