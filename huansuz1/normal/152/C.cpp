#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#define f first
#define s second
//#define mp make_pair 
#define ll long long

using namespace std;
string s[123];
char x[234][234];
int n,m,a[29];
ll ans=1;

int main(){   
    cin>>n>>m;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) 
            cin>>x[i][j];

    for (int j=0; j<m; j++){
        
        for (int i=0; i<n; i++)
            a[x[i][j]-'A']=1;
        int sum=0;
        for (int i=0; i<=25; i++) {
            sum+=a[i];
            a[i]=0;
        }
        ans=(ans*sum)%1000000007;
            
    }
    cout<<ans;

return 0;
}