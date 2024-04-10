#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,k,a,b,i;
	cin >> n >> k;
	vector<int> id;
	for(i=0;i<n;i++){
		cin >> a;
		id.push_back(a);
	}
	b = 0;
	i=1;
	while(b<k){
		a = b;
		b+=i;
		i++;
	}
	cout << id[k-a-1];
	return 0;
}