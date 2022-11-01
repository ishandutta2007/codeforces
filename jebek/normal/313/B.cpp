#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    long n,a[100000]={0},l,r;
    string s;
    cin>>s;
    for(long i=1;i<s.size();i++)
    {
        a[i]=a[i-1];
        if(s[i]==s[i-1])
            a[i]++;
    }
    cin>>n;
    for(long i=0;i<n;i++)
    {
        cin>>l>>r;
        cout<<a[r-1]-a[l-1]<<endl;
    }
}