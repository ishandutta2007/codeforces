#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,s;
    cin>>n>>s;
    if(s<2*n)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    for(int i=1;i<n;i++)
    {
        cout<<2<<" ";
    }
    cout<<s+2-2*n<<endl<<1<<endl;
    return 0;
}