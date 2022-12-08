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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);
    
    int c00,c01,c02,c10,c11,c12,c20,c21,c22;
    cin>>c00>>c01>>c02>>c10>>c11>>c12>>c20>>c21>>c22;

    int r00,r01,r02,r10,r11,r12,r20,r21,r22;

    r00=c00+c01+c10;
    r01=c01+c00+c02+c11;
    r02=c02+c01+c12;
    r10=c00+c10+c20+c11;
    r11=c10+c12+c11+c01+c21;
    r12=c02+c12+c22+c11;
    r20=c10+c20+c21;
    r21=c20+c11+c22+c21;
    r22=c22+c12+c21;

    cout<<1-r00%2<<1-r01%2<<1-r02%2<<endl;
    cout<<1-r10%2<<1-r11%2<<1-r12%2<<endl;
    cout<<1-r20%2<<1-r21%2<<1-r22%2<<endl;

    return 0;

}