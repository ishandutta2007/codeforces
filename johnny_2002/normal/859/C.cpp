#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,int> ii;

#define X first
#define Y second

int n,a[60];

int f[60][2];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=n;i>=1;i--){
        f[i][0]=max(f[i+1][1]+a[i],f[i+1][0]);
        f[i][1]=min(f[i+1][0],f[i+1][1]+a[i]);
    }
    int sum=0;
    for(int i=1;i<=n;i++) sum+=a[i];
    cout<<sum-f[1][0]<<" "<<f[1][0];
}