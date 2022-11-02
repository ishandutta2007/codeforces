#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
long long xd[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a>>b;
    for(int x=0;x<a;x++)
        cin>>tab[x];
    sort(tab,tab+a);
    long long suma=0;
    for(int x=1;x<=a;x++)
    {
        xd[x]=tab[x-1]+xd[max(0,x-b)];
        suma+=xd[x];
        cout<<suma<<" ";
    }
	return 0;
}