#include<bits/stdc++.h>
using namespace std;
bool odw[1005][1005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        int pom=b/a,pom2=b%a;
        if(pom2!=0)
            cout<<2;
        else
            cout<<0;
        cout<<'\n';
        for(int x=0;x<a;x++)
        {
            int pom3=pom;
            if(pom2)
            {
                pom2--;
                pom3++;
            }
            for(int y=x;pom3;y=(y+1)%a)
            {
                odw[x][y]=true;
                pom3--;
            }
        }
        for(int x=0;x<a;x++)
        {
            for(int y=0;y<a;y++)
            {
                cout<<odw[x][y];
                odw[x][y]=false;
            }

            cout<<'\n';
        }
    }
	return 0;
}