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
        bool czy=false;
        for(int x=2;x<=1e5;x++)
            if(a%x==0)
            {
                cout<<a/x<<" "<<a-a/x<<'\n';
                czy=true;
                break;
            }
        if(!czy)
        {
            cout<<1<<" "<<a-1<<'\n';
        }
    }
	return 0;
}