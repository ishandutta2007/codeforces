#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    long long suma=0,maks=0,b;
    int a;
    cin>>a;
    while(a--)
    {
        cin>>b;
        suma+=b;
        maks=max(maks,b);
    }
    if(suma%2==0&&2*maks<=suma)
        cout<<"YES";
    else
        cout<<"NO";
	return 0;
}