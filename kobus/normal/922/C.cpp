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
#define MAXN 2123456
#define INF LLONG_MAX
#define MOD 999999599
#define cte 10002
#define MAX 21234


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);

    int n,k;
    cin>>n>>k;

    if(n==1 && (k==1 || k==2)){
        cout<<"Yes"<<endl;
        return 0;
    }
    if(k>=n){
        cout<<"No"<<endl;
        return 0;
    }
    if(k>1123456){
        cout<<"No"<<endl;
        return 0;
    }
    for(int i=1;i<=k;i++){
        if((n%i)!=(i-1)){
            cout<<"No"<<endl;
            return 0;
        }
    }

    cout<<"Yes"<<endl;

    return 0;

}