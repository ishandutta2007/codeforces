#include <iostream>
#include<string>
#include<algorithm>

using namespace std;

int x,n;
string s,s1[200000],s2[200000];

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s1[i]>>s2[i];
        if(s1[i]>s2[i])
            swap(s1[i],s2[i]);
    }
    for(int i=0;i<n;i++)
    {
      //  cout<<i<<" "<<s<<endl;
        cin>>x;
        x--;
        if(i==0)
            s=s1[x];
        else if(s2[x]<=s)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        else if(s1[x]<=s)
            s=s2[x];
        else
            s=s1[x];
    }
    cout<<"YES"<<endl;
}