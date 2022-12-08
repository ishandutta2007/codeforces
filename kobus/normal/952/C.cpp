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
#define MAX ULLONG_MAX

int v[12];

int n;
int fmax(){
    int resp=0;
    for(int i=0;i<n;i++)resp=max(resp,v[i]);
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(1);
    cout.setf(ios::fixed);
    
    cin>>n;

    for(int i=0;i<n;i++)cin>>v[i];

    while(n>1){
        for(int i=0;i<n-1;i++){
            if(abs(v[i]-v[i+1])>1){
                cout<<"NO"<<endl;
                return 0;
            }
        }
        int num=fmax();
        int rm=0;
        for(int i=0;i<n-1;i++){
            if(rm){
                v[i]=v[i+1];
            }
            else{
                if(v[i]==num){
                    i--;
                    rm=1;
                }
            }
        }
        n--;
    }

    cout<<"YES"<<endl;


    return 0;

}