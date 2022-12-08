#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 212345
#define INF numeric_limits<ll>::max()
#define MOD 1000000007
#define eps 1e-15
#define eeps
#define cood long double

int towers[212345];
int comh[212345];


int32_t main(){
    cout.precision(12);
    cout.setf(ios::fixed);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        towers[0]++;
        towers[x]--;
    }
    comh[0]=towers[0];
    for(int i=0;i<MAXN;i++)
        comh[i]=comh[i-1]+towers[i];
    //for(int i=0;i<10;i++)cout<<comh[i]<<" ";
    //cout<<endl;
    int resp=0;
    int left=k;
    for(int i=MAXN-1;i>=0;i--){
        //cout<<left<<endl;
        if(comh[i]==n){
            if(left!=k)resp++;
            break;
        }
        if(left-comh[i]<0){
            left=k;
            resp++;
        }
        left-=comh[i];
    }
    cout<<resp<<endl;
}