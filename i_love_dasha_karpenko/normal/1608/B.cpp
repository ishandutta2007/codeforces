#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define all(var) var.begin(), var.end()
#define mp make_pair
#define gp(x,y) ((x-1)*m+y-1)
const int N = 1e5+7;
int A[N];
void solve(){
    int n,a,b;
    cin>>n>>b>>a;
    if (a+b>n-2 || abs(a-b)>1){
        cout<<"-1\n";
        return;
    }
    int flag = 0;
    if (a>b){
        swap(a,b);
        flag = 1;
    }
    A[1] = 1;
    for(int i = 2;i<=a*2+1;i+=2){
        A[i] = i+1;
        A[i+1] = i;
    }
    if (b>a){
        A[a*2+2] = n;
        int ptr = n-1;
        for(int i = a*2+3;i<=n;++i){
            A[i] = ptr--;
        }
    }
    else{
        for(int i = a*2+2;i<=n;++i)
            A[i] = i;
    }
    if (flag)
        for(int i = 1;i<=n;++i)
            A[i] = n+1-A[i];
    for(int i = 1;i<=n;++i)
        cout<<A[i]<<' ';
    cout<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin>>t;
    while(t--)
        solve();
}