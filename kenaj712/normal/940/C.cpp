#include<bits/stdc++.h>
using namespace std;
set<char> s;
set<char>::iterator it;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a,b;
	string c,d="";
	cin>>a>>b>>c;
	for(auto x:c)
        s.insert(x);
	if(b>a)
    {
        d=c;
        b-=a;
        while(b--)
            d+=*s.begin();
        cout<<d;
    }
    else
    {
        bool czy=false;
        for(int x=b-1;x>=0;x--)
        {
            it=s.find(c[x]);
            it++;
            if(it!=s.end()&&czy==false)
            {
                czy=true;
                d+=*it;
            }
            else if(czy==false)
                d+=*s.begin();
            else
                d+=c[x];
        }
        reverse(d.begin(),d.end());
        cout<<d;
    }
	return 0;
}