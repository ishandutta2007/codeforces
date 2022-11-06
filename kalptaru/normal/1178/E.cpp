#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
bool isPrime(int n) 
{  
    if (n <= 1) 
        return false;
    int a=pow(n,0.5);
    for (int i = 2; i <=a; i++) 
        if (n % i == 0) 
            return false; 
  
    return true; 
}using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin>>s;
	vector <char> d;
	int n=s.size();
	if(n%2==0)
	{
		
	}
	for(int i=0;i<n/2;i+=2)
	{
		if(s[i]==s[n-i-1] || s[i] ==s[n-i-2])
		d.push_back(s[i]);
		else
		d.push_back(s[i+1]);
	}
	for(int i=0;i<d.size();i++)
	cout<<d[i];
	if(n%4<2)cout<<d[d.size()-1];
	for(int i=1;i<d.size();i++)
	cout<<d[d.size()-i-1];
}