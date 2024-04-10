#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    int pom=0;
    for(int x=1;x<=a;x++)
        cin>>tab[x];
    for(int x=1;x<=a;x++)
    {
        while(x!=tab[x])
        {
            swap(tab[x],tab[tab[x]]);
            pom++;
        }
    }
    if((a-pom)%2==0)
        cout<<"Petr";
    else
        cout<<"Um_nik";
	return 0;
}