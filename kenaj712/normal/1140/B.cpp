#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t,a,licz;
    cin>>t;
    string b;

    while(t--)
    {
        cin>>a>>b;
        int licz1=0,licz2=0,where1=0,where2=a-1;
        while(b[where1]=='<')
        {
            licz1++;
            where1++;
            if(where1==a)
                break;
        }
        while(b[where2]=='>')
        {
            licz2++;
            where2--;
            if(where2==-1)
                break;
        }
        cout<<min(licz1,licz2)<<'\n';
    }
	return 0;
}