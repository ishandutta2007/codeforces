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
#define MAXN 112345
#define MAXM 1123456
#define INF LLONG_MAX/2
#define MOD 1000000007
#define cte 10002
#define MAX ULLONG_MAX
#define kada cout<<"karadola"<<endl;

int v[1123];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);
     
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>v[i];
    int com=0,fim=n-1;
    int resp=0;
    while(com<=fim){
        if(v[com]<=k){
            com++;resp++;
        }
        else break;
    }
    while(com<=fim){
        if(v[fim]<=k){
            fim--;resp++;
        }
        else break;
    }
    cout<<resp<<endl;

    return 0;
}