//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 big;
//#define endl '\n'
#define all(vec) vec.begin(),vec.end()
#define int ll
int ask(int a,int b){
    if (a==-1){
        return b;
    }
    if (b==-1){
        return a;
    }
    cout<<"? "<<a<<' '<<b<<endl;
    int ret;
    cin>>ret;
    return ret;
}
pair<int,int> calc(int l,int r){
    if (r-l+1==1){
        return {l,-1};
    }
    int mid = (l+r)/2;
    auto lb = calc(l,mid);
    auto rb = calc(mid+1,r);
    if (lb.second==-1 && rb.second==-1){
        return {lb.first,rb.first};
    }
    else{
        int r1 = ask(lb.second,rb.first);
        int b1 = -1;
        if (r1!=0){
            int b2;
            if (r1==1){
                b1 = lb.second;
                b2 = rb.second;
            }
            else{
                b1 = rb.first;
                b2 = lb.first;
            }
            int r2 = ask(b1,b2);
            if (r2==1){
                return {b1,-1};
            }
            else if (r2==2){
                return {b2,-1};
            }
            else{
                assert(0);
            }
        }
        else{
            int r2 = ask(lb.first,rb.second);
            if (r2==1){
                return {lb.first,-1};
            }
            else if (r2==2){
                return {rb.second,-1};
            }
            else{
                assert(0);
            }
        }
    }
}
void solve(){
    int n;
    cin>>n;
    auto ret = calc(1,(1<<n));
    int ans;
    if (ret.second!=-1){
        int r = ask(ret.first,ret.second);
        assert(r!=0);
        if (r==1){
            ans = ret.first;
        }
        else{
            ans = ret.second;
        }
    }
    cout<<"! "<<ans<<endl;
}

signed main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}