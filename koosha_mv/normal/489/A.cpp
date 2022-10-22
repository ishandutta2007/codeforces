#include<iostream>
using namespace std;
int n,a[3005];
int main() {
	int i,j,k;
	cin>>n;
	for (i=0; i<n; i++) 
		cin>>a[i];
	cout<<n<<endl;
	for (i=0; i<n; i++) 
	{
		k = i;
		for (j=i; j<n; j++)
			if (a[j] < a[k])
				k = j;
		cout<<i<<' '<<k<<endl;
		swap(a[i], a[k]);
	}
}