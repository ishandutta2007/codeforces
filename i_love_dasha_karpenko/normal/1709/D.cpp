//#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
//#define int ll
#define x1 sdfs
#define y1 sdfdsf
const int N = 2e5+7;
const int INF = 1e9+7;
struct tree{
    int T[N*2];
    void buildtree(int t,int tl,int tr,int *A){
        if (tl==tr){
            T[t] = A[tl];
            return;
        }
        int tm = (tl+tr)/2;
        buildtree(t+1,tl,tm,A);
        buildtree(t+(tm-tl+1)*2,tm+1,tr,A);
        T[t] = max(T[t+1],T[t+(tm-tl+1)*2]);
    }
    int get(int t,int tl,int tr,int l,int r){
        if (tl>r || l>tr){
            return 0;
        }
        if (l<=tl && tr<=r){
            return T[t];
        }
        int tm = (tl+tr)/2;
        return max(get(t+1,tl,tm,l,r),get(t+(tm-tl+1)*2,tm+1,tr,l,r));
    }
} T;
int A[N];
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=m;i+=1){
        cin>>A[i];
    }
    T.buildtree(0,1,m,A);
    int q;
    cin>>q;
    for(int qe = 1;qe<=q;qe+=1){
        int x1,y1,x2,y2,k;
        cin>>y1>>x1>>y2>>x2>>k;
        int mi = y1+(n-y1)/k*k;
        if (T.get(0,1,m,min(x1,x2),max(x1,x2))<mi && (x1-x2)%k==0 && (y1-y2)%k==0){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
  //  cin>>t;
    while(t--){
        solve();
    }
    return 0;
}