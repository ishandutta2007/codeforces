#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
#define y1 dfsd
#define y2 fgfdgfd
const int N = 1e5+7;
int n,y1,m,y2,A[2][N];
int Check(int type,int ost,int mod){
    int r = 0;
    for(int i = 0;i<(type==0?n:m);++i){
        if (A[type][i]%mod==ost)
            ++r;
    }
    return r;
}

int F(int type,int a,int b){
    if (a==b)
        return 1;
    int dist = abs(a-b);
    int r = 0;
    for(int div = 1;div*div<=dist;++div){
        if (dist%div)
            continue;
        r = max(r,Check(type,a%(div*2),div*2)+Check(type^1,(a+div)%(div*2),div*2));
        div = dist/div;
        r = max(r,Check(type,a%(div*2),div*2)+Check(type^1,(a+div)%(div*2),div*2));
        div = dist/div;
    }

    return r;
}
void solve(){
    cin>>n>>y1;
    for(int i = 0;i<n;++i)
        cin>>A[0][i];
    cin>>m>>y2;
    for(int i = 0;i<m;++i){
        cin>>A[1][i];
    }
    int res = 2;
    for(int cur = 1;cur<=20;++cur){
        int a = rand()%n,b = rand()%n;
        res = max(res,F(0,A[0][a],A[0][b]));
    }
    for(int cur = 1;cur<=20;++cur){
        int a = rand()%m,b = rand()%m;
        res = max(res,F(1,A[1][a],A[1][b]));
    }
    cout<<res<<endl;
}
int main() {

    int t;
    t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}