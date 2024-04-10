#include <bits/stdc++.h>
using namespace std;
int primes[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
int main()
{
	int cnt = 0;

	for(int i = 0;primes[i]*primes[i]<=100;i++)
	{
		cout<<primes[i]*primes[i]<<endl;
		cout<<flush;
		string s;
		cin>>s;
		if(s == "yes")
		{
			cout<<"composite\n";
			cout<<flush;
			return 0;
		}
	}

	for(int i = 0;primes[i]<=50;i++)
	{
		cout<<primes[i]<<"\n";
		cout<<flush;
		string s;
		cin>>s;
		if(s == "yes")
			cnt++;
	}
	bool flag = 0;
	if(cnt<=1)
		cout<<"prime"<<endl;
	else
		cout<<"composite"<<endl;
	cout<<flush;
}