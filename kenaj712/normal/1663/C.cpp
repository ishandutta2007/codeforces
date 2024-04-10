#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a;
	cin>>a;
	int sum = 0;
	for(int x=0;x<a;x++)
    {
        int b;
        cin>>b;
        sum += b;
    }
    cout<<sum;
	return 0;
}