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
#define MAXN 1123456
#define INF LLONG_MAX
#define MOD 32416187567
#define cte 10002
#define MAX ULLONG_MAX

int k,n;
int v[112];
int memo[112][112];
int t;


//0 cant 1 can
//book, shelves already completed
int pd(int i, int s){
    if(i==n && s==k)return 1;
    if(i>=n||s>=k)return 0;
    int &resp=memo[i][s];
    if(resp==-1){
        int num=0;
        resp=0;
        for(int j=i;j<n;j++){
            num+=v[j];
            if((num&t)==t)resp=max(resp,pd(j+1,s+1));
        }
    }
    return resp;
}


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);

    cin>>n>>k;

    for(int i=0;i<n;i++)cin>>v[i];

    int ans=0;
    
    //cout<<((1ll<<50)-1)<<endl;
    //t=1;cout<<pd(0,0)<<endl; 
    
    for(int k=60;k>=0;k--){
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                memo[i][j]=-1;
            }
        }
        t=(1ll<<k)+ans;
        //cout<<t<<" "<<pd(0,0)<<endl;
        if(pd(0,0))ans=t;
    }

    cout<<ans<<endl;

    return 0;
}