#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int a;
        cin>>a;
        if(a==1)
            cout<<-1;
        else if(a==2)
            cout<<57;
        else if(a==3)
            cout<<239;
        else if(a==4)
            cout<<6789;
        else
        {
            a--;
            cout<<2;
            while(a--)
                cout<<3;
        }
        cout<<'\n';
    }
	return 0;
}