#include<bits/stdc++.h>
using namespace std;
bool tab[100000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    long long a,b,c;
    cin>>a>>b>>c;
    c*=5;
    tab[a]=true;
    for(int x=100000000;x>=0;x--)
        if(tab[x]==true)
        {
            if(x>=b)
                tab[x-b]=true;
            if(x>=c)
                tab[x-c]=true;
        }
    for(int x=0;x<=100000000;x++)
        if(tab[x]==true)
    {

        cout<<x;
        return 0;
    }

	return 0;
}