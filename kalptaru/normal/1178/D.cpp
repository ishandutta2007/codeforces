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
	int n,m,f,d;
	cin>>n;
	m=n;
	while(1)
	{
		if(isPrime(m))
		break;
		m++;
	}
	d=m-n;
	cout<<m<<"\n";
	for(int i=1;i<n;i++)
	cout<<i<<' '<<i+1<<"\n";
	cout<<n<<' '<<1<<"\n";
	for(int i=1,j=1;j<=d/2;i+=4,j++)
	cout<<i<<' '<<i+2<<"\n"<<i+1<<' '<<i+3<<"\n";
	if(d%2==1)
	{
		f=d/2;
		f*=4;
		cout<<f+1<<' '<<f+3;
	}
	return 0;
	
}