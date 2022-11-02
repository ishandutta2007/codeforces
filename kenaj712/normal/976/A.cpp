#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    char b;
    bool czy=false;
    int pom=0;
    for(int x=0;x<a;x++)
    {
        cin>>b;
        if(b=='1')
            czy=true;
        else
            pom++;
    }
    if(czy==false)
        cout<<0;
    else
    {
        cout<<1;
        while(pom--)
            cout<<0;
    }
	return 0;
}