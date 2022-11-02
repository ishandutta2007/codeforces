#include<bits/stdc++.h>
using namespace std;
string tab[1005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a>>b;
    for(int x=0;x<a;x++)
        cin>>tab[x];
    int pom1=0,pom2=0,pom3,pom4,pom5,pom6=0,pom7=1;
    for(int x=0;x<a;x++)
    {
        pom5=0;
        for(auto y:tab[x])
        {
            if(y=='*')
                pom5++;
        }
        pom6+=pom5;
        if(pom5>1)
        {
            pom3=x;
            pom1++;
        }

    }
    for(int y=0;y<b;y++)
    {
        pom5=0;
        for(int x=0;x<a;x++)
        {
            if(tab[x][y]=='*')
                pom5++;
        }
        if(pom5>1)
        {
            pom4=y;
            pom2++;
        }

    }
    if(pom1!=1||pom2!=1)
        cout<<"NO";
    else
    {
        if(tab[pom3][pom4]!='*')
        {
            cout<<"NO";
            return 0;
        }
        pom1=pom3-1;
        pom2=pom4;
        while(pom1>=0)
        {
            if(tab[pom1][pom2]=='*')
            {
                pom7++;
                pom1--;
            }
            else
                break;
        }
        if(pom1==pom3-1)
        {
            cout<<"NO";
            return 0;
        }
        pom1=pom3+1;
        pom2=pom4;
        while(pom1<a)
        {
            if(tab[pom1][pom2]=='*')
            {
                pom7++;
                pom1++;
            }
            else
                break;
        }
        if(pom1==pom3+1)
        {
            cout<<"NO";
            return 0;
        }
        pom1=pom3;
        pom2=pom4-1;
        while(pom2>=0)
        {
            if(tab[pom1][pom2]=='*')
            {
                pom7++;
                pom2--;
            }
            else
                break;
        }
        if(pom2==pom4-1)
        {
            cout<<"NO";
            return 0;
        }
        pom1=pom3;
        pom2=pom4+1;
        while(pom2<b)
        {
            if(tab[pom1][pom2]=='*')
            {
                pom7++;
                pom2++;
            }
            else
                break;
        }
        if(pom2==pom4+1)
        {
            cout<<"NO";
            return 0;
        }
        if(pom6!=pom7)
            cout<<"NO";
        else
            cout<<"YES";
    }



	return 0;
}