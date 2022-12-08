#include <bits/stdc++.h>
using namespace std;
#define INF LLONG_MAX
#define f first
#define s second
#define pb push_back
#define MAXN 212345
#define pii pair<int,int>
#define pdd pair<double,double>
#define one 1
#define int long long
#define mp make_pair
#define ld long double
#define MOD 998244353 

int32_t main(){

    cout<<"? ";
    for(int i=1;i<=100;i++){
        cout<<i<<" ";
    }
    cout<<endl;
    int x;
    cin>>x;
    x=x>>7;
    x=x<<7;
    cout<<"? ";
    for(int i=1;i<=100;i++){
        cout<<(1ll<<7)*i<<" ";
    }
    cout<<endl;
    int y;
    cin>>y;
    y&=(1<<7)-1;
    cout<<"! "<<x+y<<endl;

    return 0;
}