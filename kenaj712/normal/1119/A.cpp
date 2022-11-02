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
    int pom1=0,pom2=a-1;
    while(tab[pom1]==tab[a-1])
        pom1++;
    while(tab[pom2]==tab[0])
        pom2--;
    cout<<max(a-1-pom1,pom2);
	return 0;
}