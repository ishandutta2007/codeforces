#include <bits/stdc++.h>
using namespace std;
int tab[300];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int z;
	cin>>z;
    string a;
    cin>>a;
    int maks=0,tmp;
    for(int x=0;x<z;x++)
    {
        if('a'<=a[x]&&a[x]<='z')
            tab[(int)a[x]]++;
        else
        {
            tmp=0;
            for(int y=0;y<300;y++)
                if(tab[y]!=0)
                    tmp++;
            maks=max(tmp,maks);
            for(int y=0;y<300;y++)
                tab[y]=0;
        }
    }
    tmp=0;
            for(int y=0;y<300;y++)
                if(tab[y]!=0)
                    tmp++;
            maks=max(tmp,maks);
    cout<<maks;
	return 0;
}