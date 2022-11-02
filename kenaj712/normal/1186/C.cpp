#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    string a,b;
    cin>>a>>b;
    int pom=0;
    int suma=0,suma2=0;
    for(int x=0;x<b.size();x++)
    {
        if(b[x]=='1')
            pom++;
        if(a[x]=='1')
            suma2++;
    }
    if(suma2%2==pom%2)
        suma++;
    for(int x=b.size();x<a.size();x++)
    {
        if(a[x-b.size()]=='1')
            suma2--;
        if(a[x]=='1')
            suma2++;
        if(suma2%2==pom%2)
            suma++;
    }
    cout<<suma;





	return 0;
}