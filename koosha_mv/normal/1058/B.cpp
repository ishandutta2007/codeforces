#include<iostream>
using namespace std;
int main()
{
	int d,n,k;
	cin >> n >> d >> k;
	
	for(int i=0;i<k;i++)
	{
		int t1,t2;
		cin >> t1 >> t2;
		if(t1-d<=t2 && t2-d<=t1 && ( t1+t2>=d) && (2*n-t1)-t2>=d)
		{
			if(i!=k-1)
				cout << "YES" << endl;
			else
				cout << "YES";
		}
		else
		{	if(i!=k-1)
				cout << "NO" << endl;
			else
				cout << "NO" ;
		}
	}
	
}