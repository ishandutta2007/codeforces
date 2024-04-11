#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 212345
#define INF numeric_limits<ll>::max()
#define MOD 998244353
#define eps 1e-15
#define eeps
#define cood long double

string h="hello";

int32_t main(){
    cout.precision(12);
    cout.setf(ios::fixed);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int s;
    cin>>s;
    int m;
    cin>>m;
    int d=1;
    while(s>0){
        s--;
        if(d%m==0)s++;
        d++;
    }
    cout<<d-1<<endl;
}