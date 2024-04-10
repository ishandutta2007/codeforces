#include<bits/stdc++.h>
using namespace std;
bool odw[105][105];
int poz[105][105];
int pion[105][105];
int suma[105][105];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,k;
    char znak;
    cin>>a>>k;
    for(int x=1;x<=a;x++)
        for(int y=1;y<=a;y++)
        {
            cin>>znak;
            if(znak=='.')
                odw[x][y]=true;
        }
    for(int x=1;x<=a;x++)
    {
        int pom=0;
        for(int y=1;y<=a;y++)
        {
            pom+=odw[x][y];
            if(y>k)
                pom-=odw[x][y-k];
            if(pom==k)
                poz[x][y-k+1]=1;
        }
    }
    for(int y=1;y<=a;y++)
    {
        int pom=0;
        for(int x=1;x<=a;x++)
        {
            pom+=odw[x][y];
            if(x>k)
                pom-=odw[x-k][y];
            if(pom==k)
                pion[x-k+1][y]=1;
        }
    }
    for(int x=1;x<=a;x++)
    {
        int pom=0;
        for(int y=1;y<=a;y++)
        {
            pom+=poz[x][y];
            if(y>k)
                pom-=poz[x][y-k];
            suma[x][y]+=pom;
        }
    }
    for(int y=1;y<=a;y++)
    {
        int pom=0;
        for(int x=1;x<=a;x++)
        {
            pom+=pion[x][y];
            if(x>k)
                pom-=pion[x-k][y];
            suma[x][y]+=pom;
        }
    }
    int maks=-1,x1,y1;
    for(int x=1;x<=a;x++)
    {
        for(int y=1;y<=a;y++)
        {
            //cout<<pion[x][y]<<" ";
            if(maks<suma[x][y])
            {
                maks=suma[x][y];
                x1=x;
                y1=y;
            }
        }
    }

    cout<<x1<<" "<<y1;

	return 0;
}