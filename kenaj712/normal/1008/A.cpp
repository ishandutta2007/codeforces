#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    string a;
    cin>>a;
    for(int x=1;x<a.size();x++)
    {
        if(a[x]!='a'&&a[x]!='e'&&a[x]!='o'&&a[x]!='i'&&a[x]!='u'&&a[x-1]!='n'&&a[x-1]!='a'&&a[x-1]!='e'&&a[x-1]!='o'&&a[x-1]!='i'&&a[x-1]!='u')
        {
            //cout<<x;
            cout<<"NO";
            return 0;
        }
    }
    if(a[a.size()-1]!='a'&&a[a.size()-1]!='e'&&a[a.size()-1]!='o'&&a[a.size()-1]!='i'&&a[a.size()-1]!='u'&&a[a.size()-1]!='n')
        {
            cout<<"NO";
            return 0;
        }
    cout<<"YES";
	return 0;
}