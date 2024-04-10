#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 1E5+7;
ll A[DIM];
struct node{
    ll pos[3];
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    ll st = 0;
    for(ll i = 1;i<=n;++i){
        cin>>A[i];
        st^=A[i];
    }
    if (n%2==0 && st!=0){
        cout<<"NO\n";
        return 0;
    }
    vector<node> ans;
    ll last;
    for(ll i = 1;i+2<=n;i+=2){
        ans.push_back({i,i+1,i+2});
        A[i] = A[i+1] = A[i+2] = A[i]^A[i+1]^A[i+2];
        last = i;
    }
    while(last>2){
        ans.push_back({last-2,last-1,last});
        last-=2;
    }
    cout<<"YES\n";
    cout<<ans.size()<<endl;
    for(auto to:ans)cout<<to.pos[0]<<' '<<to.pos[1]<<' '<<to.pos[2]<<endl;
    return 0;
}