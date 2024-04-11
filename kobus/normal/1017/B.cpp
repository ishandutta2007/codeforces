#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
#define double long double
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 1123456
#define INF LLONG_MAX
#define MOD 3241618756

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout.setf(ios::fixed);

    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;

    int zm=0,um=0,zn=0,un=0;
    for(int i=0;i<n;i++){
        if(a[i]=='0' && b[i]=='0')zm++;
        if(b[i]=='0' && a[i]=='1')um++;
        if(a[i]=='1' && b[i]=='1')un++;
        if(a[i]=='0' && b[i]=='1')zn++;
    }

    int resp=zm*un+zm*um+um*zn;
    cout<<resp<<endl;

    return 0;
}