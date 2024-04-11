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
#define INF LLONG_MAX
#define MOD 1000000007
#define cte 10002
#define MAX LLONG_MAX

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);

    int a,b;
    cin>>a>>b;

    while(true){
        if(a==0 || b==0){
            cout<<a<<" "<<b<<endl;
            return 0;
        }
        if(a>=2*b)a=a%(2*b);
        if(a==0){
            cout<<a<<" "<<b<<endl;
            return 0;
        }
        if(b>=2*a)b=b%(2*a);
        if(b<2*a && a<2*b)break;
    }
    cout<<a<<" "<<b<<endl;

    return 0;
}