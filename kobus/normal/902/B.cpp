#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
#define MAXN 512345
#define INF LLONG_MAX
#define MOD 1000000007
#define cte 10002
#define MAX 21234

vector<int> are[11234];
int cor[11234];
int vis[11234];

int dfs(int cara,int c){
    int resp=0;
    vis[cara]=1;
    if(c!=cor[cara]){
        resp++;
        c=cor[cara];
    }
    for(int i=0;i<are[cara].size();i++){
        if(vis[are[cara][i]]==0){
            resp+=dfs(are[cara][i],c);
        }
    }
    return resp;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);
    
    int n;
    cin>>n;


    for(int i=2;i<=n;i++){
        int num;
        cin>>num;
        are[i].pb(num);
        are[num].pb(i);
    }
    for(int i=1;i<=n;i++)cin>>cor[i];

    cout<<dfs(1,-1)<<endl;

    return 0;

}