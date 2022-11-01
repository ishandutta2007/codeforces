#include <iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

ll n,a[10],b[10],c[10],d[10];

int main()
{
    cin>>n;
    for(int i=1;i<=4;i++)
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    for(int i=1;i<=4;i++)
    {
        if(min(a[i],b[i])+min(c[i],d[i])<=n)
        {
            cout<<i<<" "<<min(a[i],b[i])<<" "<<n-min(a[i],b[i])<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
}