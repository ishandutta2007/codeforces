#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    string d;
    cin>>d;
    if(d=="00"||d=="11"||d=="0")
    {
        cout<<"No";
        return 0;
    }
    for(int x=1;x<d.size()-1;x++)
    {
        if(d[x]=='0')
        {
            if(d[x-1]=='0'&&d[x+1]=='0')
            {
                cout<<"No";
                return 0;
            }
        }
        else
        {
            if(d[x-1]=='1'||d[x+1]=='1')
            {
                cout<<"No";
                return 0;
            }
        }
    }
    if(a>=2)
    {
        if((d[0]=='0'&&d[1]=='0')||(d[d.size()-2]=='0'&&d[d.size()-1]=='0'))
        {
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
	return 0;
}