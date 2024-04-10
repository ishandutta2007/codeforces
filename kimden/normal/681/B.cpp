#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int n;
	int a[3]= {1234567,123456,1234};
	cin >> n;
	int m = n;
	int k;
	int i=0,j=0;
	while(m>=0){
		k = m;
		j=0;
		while(k>=0){
			if(k%a[2]==0){
				cout << "YES";
				return 0;
			}
			k-=a[1];
			j++;
		}
		m -= a[0];
		i++;
	}
	cout << "NO";
	return 0;
}