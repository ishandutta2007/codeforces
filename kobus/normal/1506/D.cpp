#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define MAXN 112345
#define MOD 1000000007
#define f first
#define s second
#define pii pair<long long, long long>
#define INF LLONG_MAX
#define int long long
 
int32_t main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int t;
    cin>>t;
    while(t--){
        map<int,int> m;
        int n;
        cin>>n;
        int ma=0;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            m[x]++;
            ma=max(ma,m[x]);
        }
        int tnm=n-ma;
        int tam=n-2*tnm;
        //cout<<ma<<" "<<tnm<<" "<<tam<<endl;
        if(n%2)cout<<max(tam,1ll)<<endl;
        else cout<<max(tam,0ll)<<endl;

    }

    return 0;
}