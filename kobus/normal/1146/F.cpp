
#include <bits/stdc++.h>
 
using namespace std;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define pii pair<long long,long long>
#define MAXN 212345
#define INF LLONG_MAX
#define double long double
#define pi acos(-1)
#define MOD 998244353
#define int long long
#define eps 1e-9
 
vector<int> are[212345];
 
int memo[212345][2];
 
vector<int> memo2[212345][3];
 
int pd(int u,bool final);
//pai, cara, se precisa ir alguem com a cor do meu pai 
int pd2(int u,int i,int pr){
    //cout<<u<<" "<<i<<" "<<pr<<endl;
    if(i==are[u].size()-1 && pr==0)
        return (pd(are[u][i],1)+pd(are[u][i],0))%MOD;
    if(i==are[u].size()-1 && pr==1)
        return pd(are[u][i],1);
    if(i==are[u].size()-1 && pr==2)
        return pd(are[u][i],0);
    int &resp=memo2[u][pr][i];
    //cout<<"chega aqui"<<endl;
    if(resp!=-1)return resp;
    //cout<<"chega aqui"<<endl;
    if(pr==0){
        resp=(pd(are[u][i],0)*pd2(u,i+1,0))%MOD
        +(pd(are[u][i],1)*pd2(u,i+1,0))%MOD;
        resp%=MOD;
    }
    if(pr==1){
        resp=(pd(are[u][i],0)*pd2(u,i+1,1))%MOD
        +(pd(are[u][i],1)*pd2(u,i+1,0))%MOD;
        resp%=MOD;
    }
    if(pr==2){
        resp=(pd(are[u][i],0)*pd2(u,i+1,2))%MOD
        +(pd(are[u][i],1)*pd2(u,i+1,1))%MOD;
        resp%=MOD;
    }
    return resp;
}
 
int pd(int u,bool cor){
    //cout<<u<<" "<<final<<endl;
    if(are[u].size()==0)return 1;
    if(memo[u][cor]!=-1)return memo[u][cor];
    int val=1;
    int resp;
    //cout<<"A"<<endl;
    if(cor)resp=pd2(u,0,1);
    else resp=pd2(u,0,2);
    //cout<<u<<" "<<final<<" "<<resp<<endl;
    return memo[u][cor]=resp;
}
 
int32_t main () {
    ios_base::sync_with_stdio(false);
    cout<<setprecision(11)<<fixed;
    
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int x;
        cin>>x;
        x--;
        are[x].pb(i+1);
    }
    for(int i=0;i<n;i++)memo[i][0]=memo[i][1]=-1;
    for(int i=0;i<n;i++){
        memo2[i][0].resize(are[i].size());
        memo2[i][1].resize(are[i].size());
        memo2[i][2].resize(are[i].size());
        for(int j=0;j<are[i].size();j++)
            memo2[i][0][j]=memo2[i][1][j]=memo2[i][2][j]=-1;
    }
    cout<<pd(0,0)<<endl;
 
    return 0;
}