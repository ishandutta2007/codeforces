
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define gi(x) int(x-'0')
const int N = 40+7;
int dp[N][N][N][N],X[N];
int mult[2][N];
int norm(int x,int mod){
    x%=mod;
    if (x<0)
        x+=mod;
    return x;
}
#define gt(var,pos) (get<pos>(var))
void solve(){
    int n,A,B;
    cin>>n>>A>>B;
    mult[0][1] = mult[1][1] = 1;
    for(int i = 2;i<=n;++i){
        mult[0][i] = mult[0][i-1]*10%A;
        mult[1][i] = mult[1][i-1]*10%B;
    }
    for(int i = n;i>=1;--i){
        char ch;
        cin>>ch;
        X[i] = gi(ch);
    }
    typedef tuple<int,int,int,int> cont;
    cont fin = {-1,-1,-1,-1};
    int dif = n;
    dp[0][0][0][0] = 1;
    for(int pos = 1;pos<=n;++pos){
        for(int a = 0;a<=pos;++a){
            int b = pos-a;
            for(int d1 = 0;d1<A;++d1){
                for(int d2 = 0;d2<B;++d2){
                    dp[a][b][d1][d2] = 0;
                    if (a>0 && dp[a-1][b][norm(d1-X[pos]*mult[0][a],A)][d2]!=0){
                        dp[a][b][d1][d2] = 1;
                    }
                    else if (b>0 && dp[a][b-1][d1][norm(d2-X[pos]*mult[1][b],B)]!=0){
                        dp[a][b][d1][d2] = 2;
                    }
                    if (pos == n && d1==0 && d2==0 && dp[a][b][d1][d2]!=0 && dif>abs(a-b)){
                        dif = abs(a-b);
                        fin = {a,b,d1,d2};
                    }
                }
            }
        }
    }
    if (dif==n){
        cout<<"-1\n";
    }
    else{
        while(fin!=cont{0,0,0,0}){
            if (dp[gt(fin,0)][gt(fin,1)][gt(fin,2)][gt(fin,3)]==1){
                cout<<"R";
                gt(fin,2) = norm(gt(fin,2)-X[gt(fin,0)+gt(fin,1)]*mult[0][gt(fin,0)],A);
                gt(fin,0)--;
            }
            else{
                cout<<"B";
                gt(fin,3) = norm(gt(fin,3)-X[gt(fin,0)+gt(fin,1)]*mult[1][gt(fin,1)],B);
                gt(fin,1)--;
            }
        }
    }
    cout<<endl;
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();


    return 0;
}