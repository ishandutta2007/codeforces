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

int v[212345];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    //cout.precision(11);
    //cout.setf(ios::fixed);

    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>v[i];

    string s;
    cin>>s;

    bool in=0;
    int ft;
    for(int i=0;i<n-1;i++){
        if((s[i]=='1')&&!in){
            ft=i;
            in=1;
        }
        if((s[i]=='0')&&in){
            sort(v+ft,v+i+1);
            //cout<<"ordenou "<<in<<" "<<i<<endl;
            in=0;
        }
        //cout<<ft<<" "<<in<<endl;
    }
    if(in)sort(v+ft,v+n);

    for(int i=0;i<n;i++){
        if(v[i]!=i+1){
            cout<<"NO"<<endl;
            return 0;
        }
    }

    cout<<"YES"<<endl;


    return 0;

}