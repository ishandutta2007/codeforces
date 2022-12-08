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
#define MAX 21234

int v[MAXN];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);
    
    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        int com,fim;
        cin>>com>>fim;
        for(int j=com;j<fim;j++)v[j]=1;
    }

    int resp=1;
    for(int i=0;i<m;i++){
        if(v[i]==0)resp=0;
    }

    if(resp==1){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;


    return 0;

}