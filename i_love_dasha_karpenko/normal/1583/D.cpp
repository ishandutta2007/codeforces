#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define endl '\n'
int ask(vector<int> &V){
    cout<<"? ";
    for(int to:V)
        cout<<to+1<<' ';
    cout<<endl;
    int ret;
    cin>>ret;
    return ret;
}
const int N = 1000;
int ans[N];
signed main() {
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vector<int> V(n,0);
    ans[n] = n;
    for(int i = 1;i<n;++i){
        V[n-1] = i;
        int ret = ask(V);
        if (ret==0){
            break;
        }
        --ans[n];
    }
    for(int i = 1;i<ans[n];++i){
        for(int j = 0;j<n;++j)
            V[j] = i;
        V[n-1] = 0;
        int ret = ask(V);
        ans[ret] = ans[n]-i;
    }
    for(int i = 0;i<n;++i)
        V[i] = 0;
    for(int i = 1;i<=n-ans[n];++i){
        V[n-1] = i;
        int ret = ask(V);
        ans[ret] = ans[n]+i;
    }
    cout<<"! ";
    for(int i = 1;i<=n;++i)
        cout<<ans[i]<<' ';
    cout<<endl;


    return 0;
}