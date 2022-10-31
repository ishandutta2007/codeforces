#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const int DIM = 3E5+7;
const int INF = 2E9;
pair<int,int> A[DIM];
int temp[DIM];
void solve(){
    int n,k;
    cin>>n>>k;
    for(int i = 1;i<=k;++i){
        cin>>A[i].first;
    }
    for(int i = 1;i<=k;++i)
        cin>>A[i].second;
    sort(A+1,A+1+k);
    int ptr = 1,cur = INF;
    for(int i = 1;i<=n;++i){
        while (ptr<=k && A[ptr].first<=i){
            cur = min(cur,A[ptr].second+abs(A[ptr].first-i));
            ++ptr;
        }
        temp[i] = cur;
        ++cur;
    }
    ptr = k,cur = INF;
    for(int i = n;i>=1;--i){
        while (ptr>=1 && A[ptr].first>=i){
            cur = min(cur,A[ptr].second+abs(A[ptr].first-i));
            --ptr;
        }
        temp[i] = min(temp[i],cur);
        ++cur;
    }
    for(int i = 1;i<=n;++i)
        cout<<temp[i]<<' ';
    cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}