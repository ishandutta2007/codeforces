#include <iostream>
#include<string>
using namespace std;

int n,ans;
string a;
int main()
{
    cin>>n>>a;
    for(int i=0;i<a.size();i++)
    {
        if(i%n==0 && i!=0 && a[i-1]==a[i-2] && a[i-1]==a[i-3])
            ans++;
    }
    cout<<ans<<endl;
}