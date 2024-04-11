#include <bits/stdc++.h>
 
using namespace std;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define pii pair<long long,long long>
#define MAXN 1123456
#define INF INT_MAX
#define double long double
#define pi acos(-1)
#define MOD 1000000007
#define int long long
#define eps 1e-9
 
vector<int> are[112345];
bool cor[112345];
 
int memo[112345][2];
 
int tothe(int a,int b){
    if(b==0)return 1;
    if(b%2)return (a*tothe((a*a)%MOD,b/2))%MOD;
    return tothe((a*a)%MOD,b/2);
}
 
int inv(int x){
    return tothe(x,MOD-2);
}
 
int pd(int u,int p,int pai){
    if(u!=pai && are[u].size()==1){
        if(cor[u]==0 && p)return 0;
        return 1;
    }
    if(memo[u][p]!=-1)return memo[u][p];
    int &resp=memo[u][p];
    int jfb=1;
    for(auto x:are[u]){
        if(x!=pai)jfb=(jfb*pd(x,0,u))%MOD;
    }
    if(cor[u]==1){
        //cout<<"1 "<<u<<" "<<p<<" "<<pai<<" "<<jfb<<endl;
        return resp=jfb;
    }
    resp=0;
    if(p==0){
        resp=jfb;
    }
    for(auto x:are[u]){
        if(x!=pai){
            int jfb2=(jfb*inv(pd(x,0,u)))%MOD;
            resp+=(jfb2*pd(x,1,u))%MOD;
            resp%=MOD;
        }
    }
    //cout<<"2 "<<u<<" "<<p<<" "<<pai<<" "<<resp<<endl;
    return resp;
}
 
int32_t main () {
    ios_base::sync_with_stdio(false);
    cout<<setprecision(11)<<fixed;
 
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int x;
        cin>>x;
        are[i].pb(x);
        are[x].pb(i);
    }
    for(int i=0;i<n;i++){
        cin>>cor[i];
        memo[i][0]=memo[i][1]=-1;
    }
    cout<<pd(0,1,0)<<endl;
 
 
    
    return 0;
}