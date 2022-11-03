#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define X first
#define Y second

const int N=1e6+10;
const int MOD=1e9+7;

string s;

int f[N];
int solve(){
    int n=s.length();

    int ans=0;
    for(int i=0,na=0;i<n;i++){
        if (s[i]=='a') na++;
        else {
            if (!na) continue;
            ans=(ans+f[na])%MOD;
        }
    }
    return ans;
}
int main(){

    f[1]=1;
    for(int i=2;i<N;i++) f[i]=(2*f[i-1]+1)%MOD;
    cin>>s;
    cout<<solve();
}