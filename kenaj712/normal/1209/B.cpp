#include<bits/stdc++.h>
using namespace std;
int tab[1000005][2];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    string d;
    cin>>d;
    for(int x=0;x<a;x++)
        cin>>tab[x][0]>>tab[x][1];
    int maks=0;
    for(auto x:d)
        if(x=='1')
            maks++;
    for(int x=1;x<=10000;x++)
    {
        for(int y=0;y<a;y++)
            if((x-tab[y][1])%tab[y][0]==0&&x>=tab[y][1])
            {
                if(d[y]=='1')
                    d[y]='0';
                else
                    d[y]='1';
            }
        int pom=0;
        for(auto x:d)
            if(x=='1')
                pom++;
        maks=max(maks,pom);
    }
    cout<<maks;
	return 0;
}