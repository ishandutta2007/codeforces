#include <bits/stdc++.h>
using namespace std;
 
#define fi first
#define se second
#define pb push_back
 
typedef long long ll;
typedef pair<int, int> pii;
 
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 1e5+10;
const ll MOD = 1e9+7;
 

 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n>>a>>b;
        if(a<=b)cout<<(n+a-1)/a<<endl;
        else cout<<1<<endl;
    }
    return 0;
}