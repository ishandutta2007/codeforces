#include <iostream>
#include<algorithm>
#include<string>
#include<set>

using namespace std;

int n;
set<char>t;
string s[200000];

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>s[i];
    for(int i=0;i<s[0].size();i++)
    {
        t.clear();
        for(int j=0;j<n;j++)
            if(s[j][i]!='?')
                t.insert(s[j][i]);
        if(t.size()>1)
            cout<<"?";
        else if(t.size()==1)
            cout<<*t.begin();
        else
            cout<<"a";
    }
    cout<<endl;
}