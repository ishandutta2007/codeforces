#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

ll a[502][502];
ll r[502],c[502],d1,d2;
ll x,y;

ll n;


int main()
{
    cin >> n;
    if(n==1){
        cout << 1;
        return 0;
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            cin >> a[i][j];
            if(a[i][j]==0){
                x = i;
                y = j;
            }
            if(i==j){
                d1 += a[i][j];
            }
            if(i+j==n-1){
                d2 += a[i][j];
            }
            r[i] += a[i][j];
            c[j] += a[i][j];
        }
    }
    ll need_sum=-1;
    ll need;
    for(ll i=0;i<n;i++){
        if(i==x){
            continue;
        }
        if(need_sum<0){
            need_sum = r[i];
        }else{
            if(r[i]!=need_sum){
                cout << -1;
                return 0;
            }
        }
    }
    need = need_sum-r[x];
    if(need<=0){
        cout << -1;
        return 0;
    }
    for(ll i=0;i<n;i++){
        if(i==y){
            continue;
        }
        if(c[i]!=need_sum){
            cout << -1;
            return 0;
        }
    }
    if(need != need_sum-c[y]){
        cout << -1;
        return 0;
    }
    if((x==y && d1+need!=need_sum)||(x!=y && d1!=need_sum)){
        cout << -1;
        return 0;
    }
    if((x+y==n-1 && d2+need!=need_sum)||(x+y!=n-1 && d2!=need_sum)){
        cout << -1;
        return 0;
    }
    cout << need;
    return 0;
}