#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    if(a==1||a==2)
        cout<<"No";
    else
    {
        cout<<"Yes"<<'\n';
        cout<<1<<" "<<a<<'\n';
        cout<<a-1<<" ";
        for(int x=1;x<a;x++)
            cout<<x<<" ";
    }
	return 0;
}