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

int v[1123];

int32_t main(){
    cout.precision(12);
    cout.setf(ios::fixed);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>v[i];
    int com=0,fim=n-1;
    int a=0,b=0;
    while(com<=fim){
        if(v[com]>v[fim]){
            a+=v[com];
            com++;
        }
        else{
            a+=v[fim];
            fim--;
        }
        if(fim<com)break;
        if(v[com]>v[fim]){
            b+=v[com];
            com++;
        }
        else{
            b+=v[fim];
            fim--;
        }
    }
    cout<<a<<" "<<b<<endl;
    
}