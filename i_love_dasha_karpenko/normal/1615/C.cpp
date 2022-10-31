#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
#define all(var) var.begin(),var.end()
#define mp make_pair
#define gi(x) int(x-'0')

const int N = 1e5+7;
const int INF = 1e9+7;
bool A[N],B[N];
int n;
int Check(int flag){
    int cg[2] = {0,0},cb[2] = {0,0};
    int swp = flag;
    for(int i = 1;i<=n;++i){
        if ((A[i]^flag)!=B[i]){
            cb[A[i]^swp]++;
        }
        else cg[A[i]^swp]++;
    }
    int ret = 0;
    int steps = 0;
    while(cb[0]!=0 || cb[1]!=0){
        ++steps;
        if (steps>(n<<1))
            return INF;
        ++ret;
        if (cb[1^swp]){
            cb[1^swp]--;
            swp^=1;
            cg[1^swp]++;
        }
        else if (cg[1^swp]){
            cg[1^swp]--;
            swp^=1;
            cb[1^swp]++;
        }
        else
            return INF;
    }
    if (swp)
        return INF;
    return ret;
}
void solve() {

    cin>>n;
    for(int i = 1;i<=n;++i){
        char ch; cin>>ch;
        A[i] = gi(ch);
    }
    for(int i = 1;i<=n;++i){
        char ch; cin>>ch;
        B[i] = gi(ch);
    }
    int match = 0;
    for(int i = 1;i<=n;++i)
        match+=A[i]==B[i];
    int ret1 = Check(0);
    int ret2 = Check(1);
    int ret = min(ret1,ret2);
    if (ret==INF)
        cout<<"-1\n";
    else cout<<ret<<endl;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;

    while(t--)
        solve();
}