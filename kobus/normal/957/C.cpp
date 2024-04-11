
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
#define INF LLONG_MAX/2
#define MOD 1000000007
#define cte 10002
#define MAX LLONG_MAX

int v[112345];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(13);
    cout.setf(ios::fixed);

    int n,u;
    cin>>n>>u;

    for(int i=0;i<n;i++)cin>>v[i];

    long double resp=0;
    bool isresp=0;

    int k=0;
    for(int i=0;i<n-2;i++){
        while(k<n-1 && (v[k+1]-v[i]<=u || k<=i+1))k++;
        if(v[k]-v[i]<=u){
            //cout<<j<<endl;
            //cout<<v[i]<<" "<<v[i+1]<<" "<<v[j]<<endl;
            int j=i+1;
            resp=max(resp,(long double)(v[k]-v[j])/(v[k]-v[i]));
            isresp=1;
        }
    }

    if(isresp)cout<<resp<<endl;
    else cout<<-1<<endl;


    
    return 0;
}