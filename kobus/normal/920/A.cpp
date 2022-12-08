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


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    //cout.precision(11);
    //cout.setf(ios::fixed);

    
    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;
        vector<bool> v;
        for(int i=0;i<n;i++)v.pb(0);
        for(int i=0;i<k;i++){
            int tap;
            cin>>tap;
            v[tap-1]=1;
        }
        int resp=1;
        while(true){
            //cout<<resp<<endl;
            int falta=0;
            for(int i=0;i<n;i++)if(v[i]==0)falta=1;
            if(!falta)break;
            resp++;
            vector<int> aux;
            for(int i=0;i<n;i++)aux.pb(0);
            for(int i=0;i<n;i++){
                if(!v[i])continue;
                aux[i]=1;
                if(i>0)aux[i-1]=1;
                if(i<n-1)aux[i+1]=1;
            }
            for(int i=0;i<n;i++)v[i]=aux[i];
            aux.clear();
        }
        v.clear();
        cout<<resp<<endl;
    }






    return 0;

}