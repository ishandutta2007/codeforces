//#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define gt(tuple,el) (get<el>(tuple))
const int N = 107;
int A[N];
void solve(){
    int s,n;
    cin>>s>>n;
    memset(A,0,sizeof(A));
    int cur = 1e9;
    int ptr = 0,nt = n;
    while(cur){
        while(1){
            int can = 0;
            can = min(1,(s-max(0,nt-1))/cur);
            if (can>0){
                A[ptr]+=can*cur;
                s-=can*cur;
                nt = max(0,nt-1);
                ptr = (ptr+1)%n;
            }
            else break;
        }
        cur/=10;
    }
    for(int i = 0;i<n;++i)
        cout<<A[i]<<' ';
    cout<<endl;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}