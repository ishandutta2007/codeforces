//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
//#define int ll
const int N = 1e5+7;
int A[N],len[N];
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=m;i+=1){
        cin>>A[i];
    }
    sort(A+1,A+1+m);
    A[m+1] = A[1];
    for(int i = 1;i<=m;i+=1){
        len[i] = A[i+1]-A[i]-1;
        if (len[i]<0){
            len[i] += n;
        }
    }
    sort(len+1,len+1+m);
//    cout<<"L ";
//    for(int i = 1;i<=m;i+=1){
//        cout<<len[i]<<' ';
//    }
//    cout<<endl;
    int t = 0,res = 0;
    for(int i = m;i>=1;i-=1){
        if (t*2>=len[i]){
            //
        }
        else if (t*2+1==len[i]){
            res += 1;
            t += 1;
        }
        else{
            res += len[i]-t*2-1;
            t += min(int(2),int(len[i]-t-1));
        }
        //cout<<"G "<<i<<' '<<res<<endl;
    }
    cout<<n-res<<endl;
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