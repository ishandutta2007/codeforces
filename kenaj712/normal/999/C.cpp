#include<bits/stdc++.h>
using namespace std;
bool odw[1000006];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a>>b;
    string d;
    cin>>d;
    for(int x=97;x<=122;x++)
    {
        for(int y=0;y<d.size();y++)
        {
            if(int(d[y])==x)
            {
                odw[y]=true;
                b--;
            }
            if(b==0)
            {
                for(int z=0;z<d.size();z++)
                {
                    if(odw[z]==false)
                        cout<<d[z];
                }
                return 0;
            }
        }

    }
	return 0;
}