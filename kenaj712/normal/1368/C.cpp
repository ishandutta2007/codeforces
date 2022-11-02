#include<bits/stdc++.h>
using namespace std;
long long tab[1000005];
long long f()
{
    long long pom=1;
    for(int x=0;x<10;x++)
        pom*=tab[x];
    return pom;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    cout<<4+a*3<<'\n';
    cout<<"0 0"<<'\n';
    cout<<"1 0"<<'\n';
    cout<<"0 1"<<'\n';
    cout<<"1 1"<<'\n';
    for(int x=1;x<=a;x++)
    {
        cout<<x+1<<" "<<x+1<<'\n';
        cout<<x<<" "<<x+1<<'\n';
        cout<<x+1<<" "<<x<<'\n';
    }
	return 0;
}