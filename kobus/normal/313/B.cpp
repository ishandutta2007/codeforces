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

int sumac[112345];

int32_t main(){
    cout.precision(12);
    cout.setf(ios::fixed);
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin>>s;
    sumac[0]=(s[0]==s[1]);
    for(int i=1;i<s.size();i++)
        sumac[i]=sumac[i-1]+((i!=s.size()-1)&&s[i]==s[i+1]);
    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        a--;b--;
        cout<<(a==0?sumac[b-1]:sumac[b-1]-sumac[a-1])<<endl;
    }
}