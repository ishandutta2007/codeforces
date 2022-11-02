#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    for(int x=0;x<a;x++)
        cin>>tab[x];
    sort(tab,tab+a);
    for(int x=0;x<a;x+=2)
        cout<<tab[x]<<" ";
    int pom=a-1;
    if(pom%2==0)
        pom--;
    for(int x=pom;x>=0;x-=2)
        cout<<tab[x]<<" ";
	return 0;
}