#include<bits/stdc++.h>
using namespace std;
int tab[20];
int f(char a)
{
    return int(a)-48;
}
char f2(int a)
{
    return char(a+48);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    string b;
    cin>>a;
    cin>>b;
    for(int x=1;x<=9;x++)
        cin>>tab[x];
    bool czy=false;
    for(int x=0;x<a;x++)
    {
        if(f(b[x])>tab[f(b[x])]&&czy==true)
            break;
        else if(f(b[x])<tab[f(b[x])])
        {
            b[x]=f2(tab[f(b[x])]);
            czy=true;
        }

    }
    cout<<b;
	return 0;
}