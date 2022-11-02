#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int b;
	cin>>b;
    string a;
    cin>>a;
    int mini=1e9;
    for(int x=0;x<a.size();x++)
        for(int y=x+1;y==x+1;y++)
            for(int z=y+1;z==y+1;z++)
                for(int t=z+1;t==z+1;t++)
                {
                    if(t>=a.size())
                        break;
                    mini=min(mini,min(abs(a[x]-'A'),26-abs(a[x]-'A'))+min(abs(a[y]-'C'),26-abs(a[y]-'C'))+min(abs(a[z]-'T'),26-abs(a[z]-'T'))+min(abs(a[t]-'G'),26-abs(a[t]-'G')));
                }
    cout<<mini;
	return 0;
}