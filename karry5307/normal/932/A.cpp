#include<bits/stdc++.h>
using namespace std;
typedef int ll;
string str;
int main()
{
    cin>>str;
    cout<<str;
    for(register int i=str.length()-1;i>=0;i--)
    {
        cout<<str[i];
    }
    cout<<endl;
}