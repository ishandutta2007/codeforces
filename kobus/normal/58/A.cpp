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

string h="hello";

int32_t main(){
    cout.precision(12);
    cout.setf(ios::fixed);
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin>>s;
    int p=0;
    for(int i=0;i<s.size();i++){
        if(p<h.size()&&h[p]==s[i])p++;
    }
    if(p==h.size())cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}