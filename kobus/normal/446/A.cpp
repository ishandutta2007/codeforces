#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define MAXN 112
#define INF LLONG_MAX/4
#define double long double
#define pii pair<int,int>
#define pdd pair<double,double>
#define f first
#define s second
#define mp make_pair
#define eps 1e-11
#define pi acos(-1)
#define MOD 1000000007

int fsn[112345];
int usn[112345];
int v[112345];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n; 
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(i==0||v[i-1]>=v[i])fsn[i]=1;
        else fsn[i]=fsn[i-1]+1;
    }
    for(int i=n-1;i>=0;i--){
        if(i==n-1||v[i+1]<=v[i])usn[i]=1;
        else usn[i]=usn[i+1]+1;
    }
    //for(int i=0;i<n;i++)cout<<i<<" "<<v[i]<<" "<<fsn[i]<<" "<<usn[i]<<endl;
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,fsn[i]+1);
        ans=max(ans,usn[i]+1);
        ans=min(ans,n);
        if(i==0||i==n-1||v[i-1]+1<v[i+1])
            ans=max(ans,(i==0?0:fsn[i-1])+1+(i==n-1?0:usn[i+1]));
    }       
    cout<<ans<<endl; 


    return 0;
}