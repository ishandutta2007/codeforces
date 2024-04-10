#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a,b;
    cin>>a>>b;
    for(int x=0;x<a;x++)
        cin>>tab[x];
    sort(tab,tab+a);
    reverse(tab,tab+a);
    int pom = tab[b-1];
    int licz = 0;
    for(int x=0;x<a;x++)
        licz+=((tab[x])>=pom && tab[x]>0);
    cout<<licz;
    return 0;
}