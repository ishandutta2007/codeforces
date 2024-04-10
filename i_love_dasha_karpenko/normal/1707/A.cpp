//#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
const int N = 1e5+7;
int A[N];
void solve(){
    int n,q;
    cin>>n>>q;
    for(int i = 1;i<=n;i+=1){
        cin>>A[i];
    }
    int bq = q;
    int l = 0,r = n+1;
    while(l!=r){
        int mid = (l+r)/2;
        int cur = q;
        for(int i = mid;i<=n;i+=1){
            if (cur==0){
                break;
            }
            if (A[i]>cur){
                cur -= 1;
            }
        }
        if (cur==0){
            l = mid+1;
        }
        else{
            r = mid;
        }
    }
    l -= 1;
    int res = 0;
    vector<int> ans1;
    for(int i = 1;i<=n;i+=1){
        if (i<l){
            res += A[i]<=q;
            if (A[i]<=q){
                ans1.push_back(1);
            }
            else{
                ans1.push_back(0);
            }
        }
        else if (q>0){
            res += 1;
            q -= A[i]>q;
            ans1.push_back(1);
        }
        else{
            ans1.push_back(0);
        }
    }
    vector<int> ans2 = ans1;
    ans1.clear();
    int res2 = res;
    res = 0;
    l += 1;
    q = bq;
    for(int i = 1;i<=n;i+=1){
        if (i<l){
            res += A[i]<=q;
            if (A[i]<=q){
                ans1.push_back(1);
            }
            else{
                ans1.push_back(0);
            }
        }
        else if (q>0){
            res += 1;
            q -= A[i]>q;
            ans1.push_back(1);
        }
        else{
            ans1.push_back(0);
        }
    }
    if (res<res2){
        swap(ans1,ans2);
    }
    for(int to:ans1){
        cout<<to;
    }
    assert(q>=0);
    cout<<endl;
    //cout.flush();
}
signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}