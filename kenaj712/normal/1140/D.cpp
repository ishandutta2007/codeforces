#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    long long suma=0;
    for(int x=3;x<=a;x++)
    {
        suma+=x*(x-1);
    }
    cout<<suma;
	return 0;
}