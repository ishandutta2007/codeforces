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
    int resp=0;
    for(int i=0;i<n;i++){
        int a1,a2,a3;
        cin>>a1>>a2>>a3;
        if(a1+a2+a3>=2)resp++;
    }

    cout<<resp<<endl;

    return 0;

}