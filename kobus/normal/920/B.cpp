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
#define MAXN 212
#define INF LLONG_MAX
#define MOD 999999599
#define cte 10002
#define MAX 21234

pair<pii,int> v[1123];
int resp[1123];


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    //cout.precision(11);
    //cout.setf(ios::fixed);

    
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>v[i].f.f>>v[i].s;
            v[i].f.s=i;
        }
        sort(v,v+n);
        int t=0;
        for(int i=0;i<n;i++){
            //cout<<v[i].f.f<<" "<<v[i].f.s<<" "<<v[i].s<<endl;
            t=max(t,v[i].f.f-1);
            if(t>=v[i].s){
                resp[v[i].f.s]=0;
            }
            else{
                t++;
                resp[v[i].f.s]=t;
            }
            //cout<<resp[v[i].f.s]<<endl;
        }
        for(int i=0;i<n;i++){
            cout<<resp[i]<<" ";
        }
        cout<<endl;
    }






    return 0;

}