#include<bits/stdc++.h>
using namespace std;
long long tab[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    for(int x=1;x<=a;x++)
        cin>>tab[x];
    if(a==1)
    {
        cout<<1<<" "<<1<<'\n'<<-tab[1]<<'\n';
        for(int x=0;x<2;x++)
            cout<<1<<" "<<1<<'\n'<<0<<'\n';
        return 0;
    }
    cout<<1<<" "<<a<<'\n';
    for(int x=1;x<=a;x++)
    {
        long long pom=a-1-(tab[x]%(a-1));
        cout<<a*pom<<" ";
        tab[x]+=a*pom;
    }
    cout<<'\n';
    cout<<1<<" "<<a-1<<'\n';
    for(int x=1;x<=a-1;x++)
        cout<<-tab[x]<<" ";
    cout<<'\n';
    cout<<a<<" "<<a<<'\n';
    cout<<-tab[a]<<'\n';
	return 0;
}