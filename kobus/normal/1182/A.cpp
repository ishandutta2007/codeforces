#include <bits/stdc++.h>
using namespace std;
#define INF 1'000'000'001
#define f first
#define s second
#define pb push_back
#define MAXN 1123456
#define pii pair<int,int>
#define pdd pair<double,double>
#define one 1
#define int long long
#define mp make_pair
#define ld long double
#define double long double
#define MOD 1000000007



int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(2);
    cout.setf(ios::fixed);

    int n;
    cin>>n;

    int resp=1;
    if(n%2)cout<<0<<endl;
    else cout<<(resp<<n/2)<<endl;


    return 0;
}