
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
#define MOD 1000000007
#define int long long
#define eps 1e-9

int n;
vector<int> v;
 
pii hv[312345];
pii hm[312345];
pii hvv[312345];

pii xr(pii a,pii b){
    return mp(a.f^b.f,a.s^b.s);
}

bool checa(int i,int j){
    if(i<0)return 0;
    pii val=hvv[j];
    if(i!=0)val=xr(val,hvv[i-1]);
    return val==hv[j-i];
}

int solve(){
    int resp=0;
    for(int i=0;i<n;i++){
        hvv[i]=hm[v[i]];
        if(i!=0)hvv[i]=xr(hvv[i],hvv[i-1]);
    }
    int maxi=0;
    for(int i=0;i<n;i++){
        if(v[i]==0)maxi=0;
        else{
            maxi=max(maxi,v[i]);
            if(checa(i-maxi,i))resp++;
        }
    }
    return resp;
}
 
int32_t main () {
    ios_base::sync_with_stdio(false);
    cout<<setprecision(11)<<fixed;
    
    cin>>n;
    v=vector<int>(n);

    int resp=0;

    for(int i=0;i<n;i++){
        cin>>v[i];v[i]--;
        if(v[i]==0)resp++;
    }

    for(int i=0;i<n;i++){
        hm[i].f=rand()%MOD;
        hm[i].s=rand()%MOD;
        hv[i]=hm[i];
        if(i!=0)hv[i]=xr(hv[i],hv[i-1]);
    }

    resp+=solve();
    reverse(v.begin(),v.end());
    resp+=solve();

    cout<<resp<<endl;
 
    return 0;
}