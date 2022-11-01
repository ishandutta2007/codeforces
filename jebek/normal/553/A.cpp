#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<map>
#define X first
#define Y second

using namespace std;

typedef pair<int,int> pii;
const int MOD=1e9+7;
long long n,a[2000],c[3000][3000];
long long sum,ans;

int main()
{
    for(int i=0;i<=2000;i++)
        c[i][0]=c[i][i]=1;
    for(int i=1;i<=2000;i++)
        for(int j=1;j<i;j++){
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
            //if(i<5)
           // cout<<i<<" "<<j<<" "<<c[i][j]<<endl;
        }
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sum=a[1],ans=1;
    for(int i=2;i<=n;i++)
    {
        ans=(ans*c[sum+a[i]-1][sum])%MOD;
        sum+=a[i];
    }
    cout<<ans<<endl;
}