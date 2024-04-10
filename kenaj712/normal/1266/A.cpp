#include<bits/stdc++.h>
using namespace std;
void solve()
{
    string a;
    cin>>a;
    int licz1=0,licz2=0,licz3=0;
    for(auto x:a)
    {
        int pom=x-'0';
        if(pom==0)
            licz1++;
        if(pom%2==0)
            licz2++;
        licz3+=pom;
    }
    if(licz1>=1&&licz2>=2&&licz3%3==0)
        cout<<"red"<<'\n';
    else
        cout<<"cyan"<<'\n';
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
	return 0;
}