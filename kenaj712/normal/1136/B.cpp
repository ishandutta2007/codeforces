#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    long long a,b;
    cin>>a>>b;
    long long suma=0;
    suma=2*a+1;
    suma+=a-1;
    suma+=min(b-1,a-b);
    cout<<suma;
	return 0;
}