#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 3e5+7;
int A[N],cnt[N];
int n,m,pos[N],in_pos[N];
vector<int> ans;
void calc(int shift){
    vector<int> perm;
    for(int i = 0;i<n;++i){
        in_pos[i] = A[i];
        pos[A[i]] = i;
    }
    int res = 0;
    for(int i = 0;i<n;++i){
        if (in_pos[i]==(i-shift+n)%n)
            continue;
        int a = i,b = pos[(i-shift+n)%n];
        int e1 = in_pos[a],e2 = in_pos[b];
        swap(in_pos[a],in_pos[b]);
        pos[e2] = a,pos[e1] = b;
        ++res;
    }
    if (res<=m)
        ans.push_back(shift);
}
void solve(){
    cin>>n>>m;
    for(int i = 0;i<n;++i){
        cin>>A[i];
        --A[i];
        cnt[(i-A[i]+n)%n]++;
    }
    vector<int> shifts;
    for(int i = 0;i<n;++i){
        if ((n-cnt[i])<=m*2){
            shifts.push_back(i);
        }
    }
    for(int sh:shifts){
        calc(sh);
    }
    cout<<ans.size()<<' ';
    for(auto sh:ans)
        cout<<sh<<' ';
    cout<<endl;
    ans.clear();
    for(int i = 0;i<n;++i){
        cnt[i] = 0;
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