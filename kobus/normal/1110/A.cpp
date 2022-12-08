
#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define MAXN 512345
#define INF INT_MAX
#define int long long
#define double long double
#define pii pair<int,int>
#define f first
#define s second
#define eps 1e-11
#define pi acos(-1)

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);
    
    int b,k;
    cin>>b>>k;
    int num=0;
    for(int i=0;i<k;i++){
        int x;
        cin>>x;
        if(i!=k-1)num+=b*x;
        else num+=x;
    }
    if(num%2)cout<<"odd"<<endl;
    else cout<<"even"<<endl;

    return 0;
 
}