#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 212345
#define INF numeric_limits<ll>::max()
#define MOD 998244353
#define eps 1e-15
#define eeps
#define cood long double

int32_t main(){
    cout.precision(12);
    cout.setf(ios::fixed);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s;
    cin>>n>>s;
    string so=s;
    int has=1;
    for(int i=0;i<n;i++){
        if(has && s[i]=='0'){
            s[i]='1';
            has=0;
        }
        else if(has && s[i]=='1'){
            s[i]='0';
        }
    }
    int resp=0;
    for(int i=0;i<n;i++){
        if(s[i]!=so[i])resp++;
    }
    //cout<<s<<endl;
    cout<<resp<<endl;
    
}