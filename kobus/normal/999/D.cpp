#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
#define double long double
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 112345
#define MAXM 1123456
#define INF LLONG_MAX/2
#define MOD 1000000007
#define cte 10002
#define MAX ULLONG_MAX
#define kada cout<<"karadola"<<endl;

int v[1123456];
vector<int> ind[1123456];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);
     
    int n,m;
    cin>>n>>m;
    int needed=n/m;
    int resp=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        ind[v[i]%m].pb(i);
    }
    //number,how many needs
    set<pii> s;
    for(int i=0;i<m;i++){
        if(ind[i].size()<needed)s.insert(mp(i,needed-ind[i].size()));  
    }    
    for(int i=0;i<m;i++){
        for(int j=needed;j<ind[i].size();j++){
            pii cara;
            if(s.upper_bound(mp(i,0))!=s.end()){
                cara=*s.upper_bound(mp(i,0));
                s.erase(cara);
            }
            else{
                cara=*s.begin();
                s.erase(s.begin());
            }
            int num=v[ind[i][j]];
            if((num-(num%m)+cara.f)>=num)v[ind[i][j]]=num-(num%m)+cara.f;
            else v[ind[i][j]]=num-(num%m)+cara.f+m;
            resp+=v[ind[i][j]]-num;
            cara.s--;
            if(cara.s>0)s.insert(cara);
        } 
    }    
    cout<<resp<<endl;
    for(int i=0;i<n;i++)cout<<v[i]<<" ";
    cout<<endl;

    return 0;
}