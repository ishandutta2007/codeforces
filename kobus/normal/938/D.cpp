#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
typedef long long ll;
typedef pair<long long,long long> pii;
#define int long long
#define INF LLONG_MAX
#define MOD 1000000007
#define MAXN 1123456
#define LOGMAXN 21
#define eps 1e-9

int resp[MAXN];
vector<pii> are[MAXN];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(4);
    cout.setf(ios::fixed);

    int n,m;
    cin>>n>>m;
    vector<pair<pii,long long>> ar; 
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        ar.pb(mp(mp(a,b),c));
    }
    set<pii> cost;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        cost.insert(mp(a,i));
        resp[i]=a;
    }
    for(int i=0;i<m;i++){
        are[ar[i].f.f].pb(mp(ar[i].s,ar[i].f.s));
        are[ar[i].f.s].pb(mp(ar[i].s,ar[i].f.f));
    }
    while(cost.size()>0){
        pii u=*cost.begin();
        cost.erase(*cost.begin());
        for(int j=0;j<are[u.s].size();j++){
            if(u.f+2*are[u.s][j].f<resp[are[u.s][j].s]){
                if(cost.find(mp(resp[are[u.s][j].s],are[u.s][j].s))!=cost.end()){
                    cost.erase(cost.find(mp(resp[are[u.s][j].s],are[u.s][j].s)));
                    resp[are[u.s][j].s]=u.f+2*are[u.s][j].f;
                    cost.insert(mp(resp[are[u.s][j].s],are[u.s][j].s));
                }
            }
        }
    }
    for(int i=0;i<n;i++)cout<<resp[i]<<" ";
    cout<<endl;
    
    return 0;
}