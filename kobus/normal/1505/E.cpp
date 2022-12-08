#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define MAXN 112345
#define MOD 1000000007
#define f first
#define s second
#define pii pair<long long, long long>
#define INF LLONG_MAX/1000
#define int long long

char c[112][112];

int32_t main(){
    //cin.tie(NULL);
    //ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int posx=0,posy=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>c[i][j];
        }
    }
    int ans=0;
    if(c[posx][posy]=='*')ans++;
    //cout<<ans<<endl;
    while(true){
        int dis=INF;
        int nxtx=0,nxty=0;
        for(int i=posx;i<n;i++){
            for(int j=posy;j<m;j++){
                if(i==posx&&j==posy)continue;
                if(c[i][j]=='*' && i-posx+j-posy<dis){
                    dis= i-posx+j-posy;
                    nxtx=i;
                    nxty=j;
                }
            }
        }
        if(dis==INF)break;
        ans++;
        posx=nxtx;
        posy=nxty;
    }
    cout<<ans<<endl;

    return 0;
}