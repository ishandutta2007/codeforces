//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
#define int ll
const int N = 1e3+7;
int A[N][N],n,P[N];
bool rel[N];
int F(int x){
    if (x==P[x]){
        return x;
    }
    F(P[x]);
    rel[x] ^= rel[P[x]];
    P[x] = P[P[x]];
    return P[x];
}
bool unite(int a,int b,bool xr){
    F(a);
    F(b);

    xr ^= rel[a];
    xr ^= rel[b];
    a = P[a];
    b = P[b];
    if (a>b){
        swap(a,b);
    }
    if (a==b){
        return false;
    }
    P[b] = a;
    rel[b] = xr;
    return true;
}

int gt(int i,int j){
    F(i);
    F(j);
    bool state = rel[i]^rel[j];
    if (state){
        return A[j][i];
    }
    return A[i][j];
}
void build(int row){
    if (row==n+1){
        return;
    }

    for(int i = row;i<=n;i+=1){
        if (A[row][i]!=A[i][row]){
            unite(row,i,A[row][i]>A[i][row]);
        }
    }
//    if (un!=-1){
//        unite(un,row,0);
//    }
//    if (row==1){
//        cout<<"GDB "<<F(row)<<' '<<F(2)<<' '<<F(3)<<' '<<rel[2]<<endl;
//    }
    build(row+1);

}
void solve(){

    cin>>n;
    for(int i = 0;i<=n;i+=1){
        P[i] = i;
        rel[i] = 0;
    }
    for(int i = 1;i<=n;i+=1){
        for(int j = 1;j<=n;j+=1){
            cin>>A[i][j];
        }
    }
    build(1);
    for(int i = 1;i<=n;i+=1){
        for(int j = 1;j<=n;j+=1){
            cout<<gt(i,j)<<' ';
        }
        cout<<endl;
    }
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