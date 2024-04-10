#include<bits/stdc++.h>
using namespace std;
bool odw[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a,b,c;
	cin>>a>>b>>c;
	a=(a%b)*10;
	int pom=1;
	while(odw[a]!=true)
    {
        odw[a]=true;
        if(a/b==c)
        {
            cout<<pom;
            return 0;
        }
        pom++;
        a=(a%b)*10;
    }
    cout<<-1;

	return 0;
}