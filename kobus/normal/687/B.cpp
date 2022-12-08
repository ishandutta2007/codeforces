
#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define MAXN 312
#define INF INT_MAX
#define int long long
#define double long double
#define pii pair<int,int>
#define f first
#define s second
#define mp make_pair
#define eps 1e-11
#define pi acos(-1)
#define MOD 1000000000

int gdc(int a,int b){
    return b==0?a:gdc(b,a%b);
}

int mmc(int a, int b){
    return a*b/gdc(a,b);
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(9);
    cout.setf(ios::fixed);

    int n,k;
    cin>>n>>k;
    int thing=1;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        thing=mmc(thing,x);
        thing=gdc(thing,k);
    }
    if(thing==k)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
 
}