#include <bits/stdc++.h>
using namespace std;
#define INF 1'000'000'001
#define f first
#define s second
#define eps 1e-6
#define pb push_back
#define pii pair<int,int>
#define one 1
#define mp make_pair
#define ld long double
#define MAXN 2123456
#define mod 998244353 
#define int long long

vector<int> are[MAXN];

int fat(int n){
    int ans=1;
    for(int i=1;i<=n;i++){
        ans*=i;
        ans%=mod;
    }
    //cout<<"fat "<<n<<" "<<ans<<endl;
    return ans%mod;
}

int resp(int u,int pai){
    int nf;
    int ans;
    if(u==pai){
        nf=are[u].size();
        ans=fat(nf);
    }
    else{
        nf=are[u].size()-1;
        ans=((nf+1)*fat(nf))%mod;
    }
    ans%=mod;
    //cout<<"antes "<<u<<" "<<pai<<" "<<nf<<" "<<ans<<endl;
    //if(nf==0)return 1;
    for(auto x:are[u]){
        if(x==pai)continue;
        ans*=resp(x,u);
        ans%=mod;
    }
    //cout<<u<<" "<<ans<<endl;
    return ans%mod;
}

        
int32_t main(){

    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        are[a].pb(b);
        are[b].pb(a);
    }

    cout<<(n*resp(0,0))%mod<<endl;

    return 0;
}