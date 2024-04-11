#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define MAXN 112
#define INF LLONG_MAX/20
#define double long double
#define pii pair<int,int>
#define pdd pair<double,double>
#define f first
#define s second
#define mp make_pair
#define eps 1e-11
#define pi acos(-1)
#define MOD 1000000007


vector<int> se[5123];

int p1[5123];
int p2[5123][5123];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,q;
    cin>>n>>q;
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        for(int j=a;j<=b;j++){
            if(se[j].size()<3)se[j].pb(i);
        }
    }
    int resp=0;
    for(int i=0;i<n;i++){
        if(se[i].size()==0)resp++;
        else if(se[i].size()==1)p1[se[i][0]]++;
        else if(se[i].size()==2){
            p2[se[i][0]][se[i][1]]++;
            p2[se[i][1]][se[i][0]]++;
        }
    }
    int ans=0;
    for(int i=0;i<q;i++){
        for(int j=i+1;j<q;j++){
            ans=max(ans,n-resp-p1[i]-p1[j]-p2[i][j]);
        }
    }

    cout<<ans<<endl;

    return 0;
}