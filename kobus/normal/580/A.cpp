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

    int last=0;
    int respar=0;
    int best=0;
    int num;
    for(int i=0;i<n;i++){
        cin>>num;
        if(num>=last)respar++;
        else respar=1;
        best=max(respar,best);
        last=num;
    }
    cout<<best<<endl;

    return 0;

}