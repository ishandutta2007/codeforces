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
#define MAXN 512345
#define INF LLONG_MAX
#define MOD 32416187567
#define cte 10002
#define MAX ULLONG_MAX


int v[1123456];

int c[1123];


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);
        
    int n,k;
    cin>>n>>k;

    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<256;i++){
        c[i]=-1;
    }

    for(int i=0;i<n;i++){
        if(c[v[i]]!=-1){
            cout<<c[v[i]]<<" ";
            continue;
        }
        int gc=v[i];
        int mark=k;
        while(c[gc]==-1 && gc>=0 && mark>0){
            gc--;
            mark--;
        }
        if(gc>=0 && v[i]-c[gc]+1<=k)gc=c[gc];
        else gc++;
        //cout<<v[i]<<" "<<gc<<endl;
        for(int j=gc;j<=v[i];j++){
            c[j]=gc;
        }
        cout<<c[v[i]]<<" ";
    }

    cout<<endl;

    
    return 0;

}