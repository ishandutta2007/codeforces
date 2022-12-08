#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define MAXN 112345
#define MOD 1000000007
#define f first
#define s second
#define pii pair<long long, long long>
#define INF LLONG_MAX
#define int long long

pii p[212345];

int custo(int r1,int c1,int r2,int c2){
    if(c1-r1==c2-r2){
        if((((c1-r1)%2+2)%2)==0){
            return r2-r1;
        }
        else return 0;
    }
    if((((c1-r1)%2+2)%2)==0){
        r1++;
    }
    return ((r2-c2)-(r1-c1)+1)/2;
}
 
int32_t main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>p[i].f;
        }
        for(int i=0;i<n;i++){
            cin>>p[i].s;
        }
        sort(p,p+n);
        int resp=custo(1,1,p[0].f,p[0].s);
        for(int i=0;i<n-1;i++){
            resp+=custo(p[i].f,p[i].s,p[i+1].f,p[i+1].s);
        }
        cout<<resp<<endl;


    }

    return 0;
}