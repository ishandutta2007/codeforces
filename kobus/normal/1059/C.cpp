#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 2123456
#define INF numeric_limits<ll>::max()
#define MOD 1000000007

int solve(int n){

}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    if(n==3){
        cout<<"1 1 3"<<endl;
        return 0;
    }
    int last=1;
    int ko=2;
    int rem=n;
    while(n>0){
        //cout<<n<<" "<<last<<" "<<rem<<" "<<ko<<endl;
        for(int i=0;i<n-n/2;i++){
            cout<<last<<" ";
        }
        n=n/2;
        last=ko;
        ko*=2;
        if(n==3){
            cout<<last<<" "<<last<<" "<<3*last<<endl;
            return 0;
        }
    }
    cout<<endl;

}