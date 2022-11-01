#include<bits/stdc++.h>
using namespace std;
int a[100001] , b[100001];
int main()
{
	int n , cou = 0;
	cin >> n;
	for(int i = 0 ; i < n ; i++)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b , b + n);
	int A = 0 , B = n - 1;
	while(a[A] == b[A] && A <= B)	A++;
	if(A > B)	cout << "yes\n1 1";
	else{
		while(a[B] == b[B])	B--;
		int c = A , d = B;
		for(; B >= c ; A++ , B--)
			if(a[A] != b[B])
			{
				cout << "no";
				return 0;
			}
		cout << "yes" << endl << c + 1 << " " << d + 1;
	}
	return 0;
}