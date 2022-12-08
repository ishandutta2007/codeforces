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

int v[112];


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);
     
    int n;
    cin>>n;
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        sum+=v[i];
    }

    sort(v,v+n);
    int resp=0;
    for(int i=0;i<n;i++){
        if(2*sum>=9*n){
            cout<<resp<<endl;
            return 0;
        }
        sum-=v[i];
        sum+=5;
        resp++;
    }

    cout<<resp<<endl;

    return 0;
}