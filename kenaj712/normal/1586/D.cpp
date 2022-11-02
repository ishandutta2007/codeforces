#include<bits/stdc++.h>
using namespace std;

bool odw[1005];
int perm[1005];

int main()
{
	int a;
	cin>>a;
	int licz = 1;
	for(int x=2;x<=a;x++)
    {
        cout<<"? ";
        for(int y=1;y<=a-1;y++)
            cout<<x<<" ";
        cout<<1<<'\n';
        cout.flush();
        int b;
        cin>>b;
        if(b != 0)
            licz++;
    }

    perm[a] = licz;

    for(int x=a;x>=1;x--)
    {
        cout<<"? ";
        for(int y=1;y<=a-1;y++)
            cout<<a+1-x<<" ";
        cout<<a+1-perm[a]<<'\n';
        cout.flush();
        int b;
        cin>>b;
        perm[b] = x;
    }
    cout<<"! ";
    for(int x=1;x<=a;x++)
        cout<<perm[x]<<" ";
    cout.flush();

	return 0;
}