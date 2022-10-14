#include <iostream>

using namespace std;
#define F for(int i=0;i<n;i++)
const int N=1e5;
long long n,k,ans,a[N];string s;
int main()
{
    cin>>n;a['I']=20,a['O']=8,a['T']=4,a['C']=6,a['D']=12;
    F {cin>>s;ans+=a[s[0]];}
    cout<<ans;
    return 0;
}