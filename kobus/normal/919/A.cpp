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
#define MAXN 212
#define INF LLONG_MAX
#define MOD 999999599
#define cte 10002
#define MAX 21234

int v[212345];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);

    int n,m;
    cin>>n>>m;

    double price=INF;
    for(int i=0;i<n;i++){
        double a,b;
        cin>>a>>b;
        price=min(price,a*m/b);
    }

    cout<<price<<endl;



    return 0;

}