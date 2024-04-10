#include<bits/stdc++.h>
#define ll long long
#define fors(i,a,b) for(int i = a; i < b; ++i)
#define pb push_back
#define all(a) a.begin(),a.end()
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
int main(){
    int T; cin>>T;
    while(T--){
        int n;
        cin>>n;
        int x = 0, y = 0;
        fors(i,0,n){
            int a; cin>>a;
            if(a == 0) x ++;
            else if(a == 1) y++;
        }
        ll ans = (1LL<<x)*y;
        cout<<ans<<endl;
    }
    return 0;
}