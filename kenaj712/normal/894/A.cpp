#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    string a;
    cin>>a;
    int d=a.size();
    int licz=0;
    for(int x=0;x<d;x++)
        for(int y=x+1;y<d;y++)
            for(int z=y+1;z<d;z++)
                if(a[x]=='Q'&&a[y]=='A'&&a[z]=='Q')
                    licz++;
    cout<<licz;
	return 0;
}