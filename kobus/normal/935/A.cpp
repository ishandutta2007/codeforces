#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f first
//#define s second
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

    int n;
    cin>>n;
    int resp=0;
    for(int i=1;i<n;i++){
        if(((n-i)/i)*i==(n-i))resp++;
    }
    cout<<resp<<endl;

    return 0;

}