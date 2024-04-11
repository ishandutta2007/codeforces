using namespace std;
#include<iostream>
int a[102];
int main()
{
	int n,m,b,v;
	cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		cin >> b;
		for(int j =0;j<b;j++)
		{
			cin >> v;
			a[v]=1;
		}
	}
	int t=0;
	for(int i=1;i<m+1;i++)
	{
		if(a[i]!=1)
			t=1;
	}
	if(t==1)
		cout << "NO";
	else
		cout << "YES";
	
}