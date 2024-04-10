#include<bits/stdc++.h>
using namespace std;
set<pair<int,int> > s1;
set<pair<int,int> > s2;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a;
    for(int x=1;x<=a;x++)
    {
        cin>>b;
        s1.insert(make_pair(b,x));
    }
    string d;
    cin>>d;
    for(int x=0;x<2*a;x++)
    {
        if(d[x]=='0')
        {
            cout<<(*s1.begin()).second<<" ";
            s2.insert(make_pair(-(*s1.begin()).first,(*s1.begin()).second));
            s1.erase(s1.begin());
        }
        else
        {
            cout<<(*s2.begin()).second<<" ";
            s2.erase(s2.begin());
        }
    }
	return 0;
}