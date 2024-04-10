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
    if(a%2==1)
        cout<<tab[a/2];
    else
        cout<<tab[a/2-1];
	return 0;
}