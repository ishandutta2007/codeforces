#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a>>b;
    int wynik=0,last=-1;
    for(int x=1;x<=a;x++)
    {
        wynik+=(x-1)/2;
        if(wynik>=b)
        {
            last=x;
            break;
        }
    }
    if(last==-1)
    {
        cout<<-1;
        return 0;
    }
    wynik-=(last-1)/2;
    int zapisz=last-1;
    int pom=(b-wynik)*2;
    pom=(zapisz+zapisz-pom+1);
    for(int x=1;x<=zapisz;x++)
        cout<<x<<" ";
    cout<<pom<<" ";
    int xd=a-zapisz-1;
    int xd2=1e9;
    while(xd--)
    {
        v.push_back(xd2);
        xd2-=pom+1;
    }
    reverse(v.begin(),v.end());
    for(auto x:v)
        cout<<x<<" ";
	return 0;
}