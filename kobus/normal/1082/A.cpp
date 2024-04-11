#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define eps 1e-3
#define f first
#define s second
#define MAXN 512345
#define INF LLONG_MAX/4
#define double long double
#define MOD 1000000007


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);

    int t;
    cin>>t;
    while(t--){
        int n,x,y,d;
        cin>>n>>x>>y>>d;
        int resp=INF;
        if(abs(x-y)%d==0)resp=min(resp,abs(x-y)/d);
        if(abs(n-y)%d==0)resp=min(resp,(n-x+d-1)/d+(n-y)/d);
        if((y-1)%d==0)resp=min(resp,abs(x-1+d-1)/d+abs(y-1)/d);
        if(resp==INF)cout<<-1<<endl;
        else cout<<resp<<endl;
    }
}