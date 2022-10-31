//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define x1 dfgfg
#define y1 dfgdfg
const ll DIM = 1E5+7;
const ll INF = 1E9;
ll A[DIM],cnt[40];
ll gi(char ch){
    return ch-'a'+1;
}
char gs(ll pos){
    return char('a'+pos-1);
}
ll solve(){
    ll n,k;
    cin>>n>>k;
    memset(cnt,0,sizeof(cnt));
    ll pos = 0;
    A[n+1] = -1;
    for(ll i = 1;i<=n;++i){
        char ch;
        cin>>ch;
        A[i] = gi(ch);
    }
    for(ll i = 1;i<=n;++i){

        cnt[A[i]]++;
        ll need = 0;
        ll mx = 0;
        for(ll sy = 1;sy<=26;++sy){
            need+=(k-cnt[sy]%k)%k;
            if (cnt[sy]%k != 0)mx = sy;
        }
        if (A[i+1]>=mx && i!=n)need+=k;
        if (need<=n-i && A[i+1]!=26)
            pos = i;
    }
    if (n%k!=0){
        cout<<"-1\n";
        return 0;
    }
    memset(cnt,0,sizeof(cnt));
    for(ll i = 1;i<=pos;++i) {
        cnt[A[i]]++;
        cout<<gs(A[i]);
    }
    if (pos==n){
        cout<<endl;
        return 0;
    }
    ll flag = 0;
    ll need = 0;
    for(ll sy = 1;sy<=26;++sy){
        need+=(k-cnt[sy]%k)%k;
    }
    if (need+k<=n-pos){
        cnt[A[pos+1]+1]++;
        cout<<gs(A[pos+1]+1);
    }
    else{
        ll flag = 0;
        for(ll sy = A[pos+1]+1;sy<=26;++sy){
            if (cnt[sy]%k){
                ++cnt[sy];
                cout<<gs(sy);
                flag = 1;
                break;
            }
        }
        if (!flag)n/=0;
    }
    ++pos;
    while(pos!=n){
        ++pos;
        ll flag = 0;
        ll need = 0;
        for(ll sy = 1;sy<=26;++sy){
            need+=(k-cnt[sy]%k)%k;
        }
        if (need+k<=n-pos+1){
            cout<<'a';
            ++cnt[1];
            continue;
        }
        for(ll sy = 1;sy<=26;++sy){
            if (cnt[sy]%k){
                cout<<gs(sy);
                ++cnt[sy];
                flag = 1;
                break;
            }
        }
        if (flag==0){
            cout<<'a';
            ++cnt[1];
        }
    }
    cout<<endl;



    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
        solve();

    return 0;
}