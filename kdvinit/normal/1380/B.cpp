/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

void solve()
{
    string s;
    cin>>s;

    int n=s.size(),cntr=0,cnts=0,cntp=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='R') cntr++;
        if(s[i]=='P') cntp++;
        if(s[i]=='S') cnts++;
    }

    int m=max(cntr,max(cnts,cntp));
    //cout<<m<<" "<<cntr<<" "<<cnts<<" "<<cntp<<endl;

    char a='V';
    if(cntr==m) a='P';
    if (cntp==m) a='S';
    if (cnts==m) a='R';

    for(int i=0;i<n;i++) cout<<a;
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
        solve();
	}
	return 0;
}