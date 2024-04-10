#include <iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<cstring>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll n;

int main()
{
    cin>>n;
    if(n%2==0)
    {
        cout<<-1<<endl;
        return 0;
    }
    for(int i=0;i<n;i++)
        cout<<i<<" ";
    cout<<endl;
    for(int i=1;i<n;i++)
        cout<<i<<" ";
    cout<<0<<endl;
    for(int i=0;i<n-1;i++)
        cout<<(2*i+1)%n<<" ";
    cout<<n-1<<endl;
}