#include<bits/stdc++.h>
using namespace std;
int tab[505][505];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a>>b;
    for(int x=0;x<a;x++)
        for(int y=0;y<b;y++)
            cin>>tab[x][y];
    int kor=0;
    for(int x=0;x<a;x++)
        kor^=tab[x][0];
    if(kor!=0)
    {
        cout<<"TAK"<<'\n';
        while(a--)
            cout<<1<<" ";

    }
    else
    {
        for(int x=0;x<a;x++)
            for(int y=1;y<b;y++)
                if(tab[x][y]!=tab[x][0])
                {
                    cout<<"TAK"<<'\n';
                    for(int z=0;z<a;z++)
                    {
                        if(z==x)
                            cout<<y+1<<" ";
                        else
                            cout<<1<<" ";

                    }
                    return 0;
                }
        cout<<"NIE";
    }
	return 0;
}