#include<algorithm>
#include<iostream>
#include<string>
 
using namespace std;
int main()
{

long long n,k;
cin>>n>>k;
long long a=(n-k);
long long b=n/k;
cout<<(k-n%k)*((b-1)*(b))/2+(n%k)*((b)*(b+1))/2<<" "<<(a*(a+1))/2;
return 0;
}