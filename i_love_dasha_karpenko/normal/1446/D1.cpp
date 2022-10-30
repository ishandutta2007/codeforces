#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define x1 dfds
#define y1 dsfdsfe
#define endl '\n'

const ll DIM = 2E5+7;
const ll DIM1 = 107;
ll A[DIM],cnt[DIM1];
ll M[DIM1][DIM*2];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    for(ll i = 1;i<=n;++i){
        cin>>A[i];
        ++cnt[A[i]];
    }
    ll mx = 0,flag = 0,el = 0;
     memset(M,-1,sizeof(M));
    for(ll i = 1;i<DIM1;++i){
        if (mx==cnt[i]){
            flag = 1;
        }
        else if (mx<cnt[i]){
            mx = cnt[i];
            el = i;
            flag = 0;
        }
        M[i][DIM] = 0;
    }
    if (flag){
        cout<<n<<endl;
        return 0;
    }
    memset(cnt,0,sizeof(cnt));
    ll ct = 0,res = 0;

    for(ll i = 1;i<=n;++i){
        cnt[A[i]]++;
        if (A[i]==el)
            ++ct;
        for(ll j = 1;j<DIM1;++j){
            if (j==el)continue;
            if (M[j][cnt[j]-ct+DIM]==-1)
            M[j][cnt[j]-ct+DIM] = i;
            else{
                res = max(res,i-M[j][cnt[j]-ct+DIM]);
            }
        }


    }
    cout<<res<<endl;

    return 0;
}