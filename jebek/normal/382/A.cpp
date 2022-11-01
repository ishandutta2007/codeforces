#include <iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<cstring>

using namespace std;

string s1,s2;
long long k,p;

int main()
{
    cin>>s1>>s2;
    for(int i=0;i<s1.size();i++)
        if(s1[i]=='|')
        {
            p=i;
            break;
        }
    if((s1.size()+s2.size())%2==0 || max(p,s1.size()-p-1)>min(p,s1.size()-p-1)+s2.size())
    {
        cout<<"Impossible"<<endl;
        return 0;
    }
    k=(s1.size()+s2.size()-1)/2;
    for(int i=0;i<p;i++)
        cout<<s1[i];
    for(int i=0;i<k-p;i++)
        cout<<s2[i];
    for(int i=p;i<s1.size();i++)
        cout<<s1[i];
    for(int i=k-p;i<s2.size();i++)
        cout<<s2[i];
    cout<<endl;
}