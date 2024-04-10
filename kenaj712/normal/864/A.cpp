#include <bits/stdc++.h>
using namespace std;
int tab[105];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,d=1,b,c,e,f;
    cin>>a;
    for(int x=0;x<a;x++)
        cin>>tab[x];
        sort(tab,tab+a);
    for(int x=0;x<a-1;x++)
    {
        if(tab[x]!=tab[x+1])
            d++;
    }
    if(d!=2)
        cout<<"NO";
    else
    {
        b=tab[0],c=tab[a-1],f=0,e=0;
        for(int x=0;x<a;x++)
        {
            if(tab[x]==b)
                f++;
            else
                e++;

        }
       for(int x=0;x<a-1;x++)
        {
          if(tab[x]!=tab[x+1]&&f==e)
          {
             cout<<"YES"<<'\n'<<tab[x]<<" "<<tab[x+1];
             return 0;
          }

        }
        cout<<"NO";
    }

	return 0;
}