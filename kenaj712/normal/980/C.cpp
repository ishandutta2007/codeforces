#include<bits/stdc++.h>
using namespace std;
int tab2[600];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for(int x=0;x<=255;x++)
        tab2[x]=256;
    int a,b,c;
    cin>>a>>b;
    for(int x=0;x<a;x++)
    {
        cin>>c;
        if(tab2[c]==256)
        {
            int pom=0;
            for(int y=c;y>max(c-b,-1);y--)
            {
                if(tab2[y]!=256)
                {
                    if(c-tab2[y]+1<=b)
                    pom=tab2[y];
                    else
                        pom=y+1;
                    break;
                }
                if(y==c-b+1)
                    pom=c-b+1;
            }
            for(int y=pom;y<min(pom+b,c+1);y++)
                tab2[y]=pom;
            cout<<pom<<" ";
        }
        else
            cout<<tab2[c]<<" ";
    }

	return 0;
}