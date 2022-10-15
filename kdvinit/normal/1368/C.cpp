/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	int n;
	cin>>n;
	n++;

	cout<<3*n+1<<endl;
	cout<<0<<" "<<0<<endl;

	for(int i=1;i<=n;i++)
    {
        cout<<i<<" "<<i<<endl;
        cout<<i<<" "<<i-1<<endl;
        cout<<i-1<<" "<<i<<endl;
    }

	return 0;
}