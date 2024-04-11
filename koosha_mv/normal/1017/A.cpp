#include<iostream>
using namespace std;
int n;
int main()
{
	
	cin >> n;
	float d1,d2,d3,d4;
	int t=1;
	int k;
	cin >> d1 >> d2 >> d3 >> d4;
	k=(d1+d2+d3+d4);
	for(int i=0;i<n-1;i++)
	{
		cin >> d1 >> d2 >> d3 >> d4;
		if(d1+d2+d3+d4>k)
		{
			
			t++;
		}
	}
	cout << t;
}