#include <bits/stdc++.h>
using namespace std;
#define INF LLONG_MAX
#define f first
#define s second
#define pb push_back
#define MAXN 212345
#define pii pair<int,int>
#define pdd pair<double,double>
#define one 1
#define int long long
#define mp make_pair
#define ld long double

int resp[212345];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(2);
    cout.setf(ios::fixed);

    int n;
    cin>>n;

    if(n%2==0){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    for(int i=0;i<n;i++){
        if(i%2==0){
            resp[i]=2*i+1;
            resp[i+n]=2*i+2;
        }
        else{
            resp[i]=2*i+2;
            resp[i+n]=2*i+1;
        }
    }
    for(int i=0;i<2*n;i++)cout<<resp[i]<<" ";
    cout<<endl;

    return 0;
}