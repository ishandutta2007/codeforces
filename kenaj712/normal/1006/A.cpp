#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    int b;
    for(int x=0;x<a;x++)
    {

        cin>>b;
        if(b%2==0)
            b--;
        cout<<b<<" ";
    }
	return 0;
}