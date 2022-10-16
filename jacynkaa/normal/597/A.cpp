#include<iostream>
using namespace std;


main ()
{
long long int k, a, b;
 
cin >>k >>a >>b;
long long X=((2e18/k));
X*=k;
b+=X;
a+=X;
//cout<<a<<" "<<b<<endl;
a--;
long long int wynik=b/k-a/k;


cout<<wynik<<endl;

}