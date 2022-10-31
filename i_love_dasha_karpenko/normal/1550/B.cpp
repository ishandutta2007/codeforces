#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const int DIM = 5007;
int A[DIM];
int solve(){
    int n,a,b;
    cin>>n>>a>>b;
    for(int i = 1;i<=n;++i){
        char ch;
        cin>>ch;
        A[i] = ch-'0';
    }
    if (b>=0){
        cout<<a*n+b*n<<endl;
        return 1;
    }
    else{
        int cnt[] = {0,0};
        A[0] = -1;
        for(int i = 1;i<=n;++i){
            if (A[i]!=A[i-1])
                ++cnt[A[i]];
        }
        cout<<a*n+min(cnt[0],cnt[1])*b+b<<endl;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        assert(solve());
    return 0;
}