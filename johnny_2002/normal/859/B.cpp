#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,int> ii;

#define X first
#define Y second

const int inf=1e9+10;
int main(){
    int n;
    cin>>n;
    int ans=inf;
    for(int i=1;i<=n;i++) ans=min(ans,(i+(n+i-1)/i)*2);
    cout<<ans;
}