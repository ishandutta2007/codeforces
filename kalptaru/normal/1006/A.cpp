#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; 
	cin>>n;
	int num;
	int arr[n];
 	for(int i=0;i<n;i++)
	{
		cin>>num;
		if(num%2==0)
		{
			arr[i]=num-1;	
		}
		else
		{
			arr[i]=num;
		}	
	}  
    for(int i=0;i<n;i++)
    {
    	cout<<arr[i]<<' ';
	}
	return 0;
}