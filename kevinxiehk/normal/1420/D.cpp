#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define int long long
using namespace std;
const int MOD=998244353;
int bigmod(int n,int po){
    if(po==1)return n;
    int t=bigmod(n,po/2);
    if(po%2==0){
        return(t*t)%MOD;
    }
    else{
        int ah=t*t%MOD;
        return(ah*n)%MOD;
    }
}
void solve(){
    int n,k,a,b;
    cin>>n>>k;
    vector<int>have;
    pair<int,int>arr[n+5];
    for(int i=0;i<n;i++){
        cin>>a>>b;
        arr[i]=mp(a,b);
        have.pb(a);have.pb(b);//cout<<"a";
    }
    sort(have.begin(),have.end());
    //cout<<"a";
    map<int,int>mp;
    int t=n*2;
    for(int i=0;i<t;i++){mp[have[i]]=i;}
    for(int i=0;i<n;i++){
        arr[i].fi=mp[arr[i].fi];
        arr[i].se=mp[arr[i].se];
    }
    //for(int i=0;i<n;i++){cout<<arr[i].fi<<" "<<arr[i].se<<endl;}
    int pre[t+5],car[t+5];
    for(int i=0;i<=t;i++)pre[i]=0;
    for(int i=0;i<=t;i++)car[i]=0;
    for(int i=0;i<n;i++){
        pre[arr[i].fi]++;
        pre[arr[i].se+1]--;
        car[arr[i].fi+1]++;
        car[arr[i].se+1]--;
    }
    for(int i=1;i<=t;i++){pre[i]+=pre[i-1];car[i]+=car[i-1];}
    int pow[n+5];
    pow[k]=1;
    for(int i=0;i<k;i++)pow[i]=0;
    for(int i=k+1;i<=n;i++){
        pow[i]=(pow[i-1]*i);
        pow[i]%=MOD;
        pow[i]*=bigmod(i-k,MOD-2);
        pow[i]%=MOD;
    }
    int ans=0;
    for(int i=0;i<t;i++){
        ans+=pow[pre[i]];
        ans-=pow[car[i]];
        while(ans<0)ans+=MOD;
        ans%=MOD;
    }
    while(ans<0)ans+=MOD;
    cout<<ans%MOD<<endl;
    return;
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
 
    //cin>>t;
    
    while(t--)solve();
    return 0;
}