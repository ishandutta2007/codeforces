#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    string b;
    cin>>a>>b;
    if(a%2==1)
    {
        cout<<"No";
        return 0;
    }
    int licz1=0,licz2=0;
    for(auto x:b)
    {
        if(x=='(')
            licz1++;
        else
            licz2++;

    }
    if(licz1!=licz2)
    {
        cout<<"No";
        return 0;
    }
    int maks1=0,maks2=0,act=0;
    for(int x=0;x<a;x++)
    {
        if(b[x]=='(')
            act++;
        else
            act--;
        maks1=min(maks1,act);
    }
    act=0;
    for(int x=a-1;x>=0;x--)
    {
        if(b[x]==')')
            act++;
        else
            act--;
        maks2=min(maks2,act);
    }
    if(max(maks1,maks2)>=-1)
        cout<<"Yes";
    else
        cout<<"No";
	return 0;
}