#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    string a;
    cin>>a;
    bool czy=false;
    string b;
    int t=5;
    while(t--)
    {
        cin>>b;
        if(a[0]==b[0]||a[1]==b[1])
            czy=true;
    }
    if(czy==true)
        cout<<"YES";
    else
        cout<<"NO";
	return 0;
}