#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    string a,b;
    cin>>a>>b;
    if(a.size()!=b.size())
    {
        cout<<"No";
        return 0;
    }
    for(int x=0;x<a.size();x++)
    {
        if(a[x]=='a'||a[x]=='e'||a[x]=='o'||a[x]=='i'||a[x]=='u')
            if(b[x]!='a'&&b[x]!='e'&&b[x]!='o'&&b[x]!='i'&&b[x]!='u')
        {
            cout<<"No";
            return 0;
        }
         if(a[x]!='a'&&a[x]!='e'&&a[x]!='o'&&a[x]!='i'&&a[x]!='u')
            if(b[x]=='a'||b[x]=='e'||b[x]=='o'||b[x]=='i'||b[x]=='u')
         {
             cout<<"No";
             return 0;
         }
    }
    cout<<"Yes";
	return 0;
}