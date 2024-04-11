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
#define MAX ULLONG_MAX

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(1);
    cout.setf(ios::fixed);
    
    int n;
    cin>>n;



    //da errado

    if(n<=5)cout<<-1<<endl;
    else{
        for(int i=2;i<n-1;i++){
            cout<<1<<" "<<i<<endl;
        }
        cout<<2<<" "<<n-1<<endl;
        cout<<2<<" "<<n<<endl;
    }

    //da certo

    for(int i=1;i<n;i++){
        cout<<i<<" "<<i+1<<endl;
    }





    return 0;

}