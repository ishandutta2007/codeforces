#include <iostream>
#include <string>

using namespace std;

int main()
{   int h=0;
    cin>>h;
    string a;
    cin>>a;
    int n=a.size();
    int open=0;
    int ans=0;
    for(int i=0; i<n-1; i++)
    {
        if(a[i]==a[i+1])
            ans++;


    }


    cout<<ans;
}