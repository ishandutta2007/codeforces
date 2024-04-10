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
        for(int x=0;x<a;x++)
        {
            int b;
            cin>>b;
            if(x%2==0)
            {
                cout<<abs(b);
            }
            else
                cout<<-abs(b);
            cout<<" ";
        }
        cout<<'\n';
    }
	return 0;
}