#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,int> ii;

#define X first
#define Y second

int main(){
    int n,ans=0;
    cin>>n;
    for(int i=1,val;i<=n;i++){
        cin>>val;
        ans=max(ans,val);
    }
    cout<<max(0,ans-25);
}