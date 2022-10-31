//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 107;
int A[N];
void solve(){
    int n;
    cin>>n;
    queue<int> Q;
    for(int i = 1;i<=n;++i){
        char ch;
        cin>>ch;
        if (ch=='B')
            A[i] = -1,Q.push(i);
        else if (ch=='R')
            A[i] = 1,Q.push(i);
        else A[i] = 0;
    }
    if (Q.empty()){
        A[1] = 1;
        Q.push(1);
    }
    while(!Q.empty()){
        int pos = Q.front();
        Q.pop();
        if (pos-1>0 && A[pos-1]==0){
            A[pos-1] = -A[pos];
            Q.push(pos-1);
        }
        if (pos+1<=n && A[pos+1]==0){
            A[pos+1] = -A[pos];
            Q.push(pos+1);
        }
    }
    for(int i = 1;i<=n;++i){
        if (A[i]==1)
            cout<<'R';
        else cout<<'B';
    }
    cout<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin>>t;
    //t = 1;
    while(t--)
        solve();
    return 0;
}