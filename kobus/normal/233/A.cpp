#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f first
#define s second
//#define int long long
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
#define MAXN 512345
#define INF LLONG_MAX
#define MOD 1000000007
#define cte 10002
#define MAX LLONG_MAX

int32_t main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.precision(11);
    //cout.setf(ios::fixed);
    int n;
    cin>>n;

    if(n%2==1){
        cout<<-1<<endl;
        return 0;
    }

    for(int i=1;i<=n;i++){
        if(i%2==1)cout<<i+1<<" ";
        else cout<<i-1<<" ";
    }
    cout<<endl;

    return 0;

}