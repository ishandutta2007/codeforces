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
        int n;
        cin>>n;
        string s;
        cin>>s;
        bool ok=1;
        bool alt=0;
        for(int i=0;i<n;i++){
            if(alt){
                if(i==n-1 || s[i+1]!=s[i]){
                    //cout<<i<<" "<<s[i]<<" "<<s[i+1]<<endl;
                    ok=0;
                }
                i++;
            }
            alt=!alt;
        }
        if(ok)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}