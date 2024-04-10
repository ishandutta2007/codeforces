/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);\

	long long int k;
	cin>>k;

	char a[10]={'c','o','d','e','f','o','r','c','e','s'};
	long long int freq[10]={1,1,1,1,1,1,1,1,1,1},val;

	int cntr=0;
	while(1)
    {
        val=freq[0]*freq[1]*freq[2]*freq[3]*freq[4]*freq[5]*freq[6]*freq[7]*freq[8]*freq[9];
        if(val>=k) break;
        freq[cntr++]++;
        if(cntr==10) cntr=0;
    }

	for(int i=0;i<10;i++)
    {
        for(int j=1;j<=freq[i];j++) cout<<a[i];
    }

	return 0;
}