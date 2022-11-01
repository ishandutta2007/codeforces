#include <iostream>
#include<algorithm>
#include<set>

using namespace std;

int n,b[300000];
set<int>s;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        s.insert(a-n+i);
    }
    if(s.size()<n)
    {
        cout<<":("<<endl;
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        int a=*(s.begin());
        s.erase(s.begin());
        a+=n-i;
        if(a<0)
        {
            cout<<":("<<endl;
            return 0;
        }
        b[i]=a;
    }
    for(int i=0;i<n;i++)
        cout<<b[i]<<" ";
    cout<<endl;
}