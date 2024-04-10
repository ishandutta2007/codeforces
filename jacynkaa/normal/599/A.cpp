#include<iostream>
#include<algorithm>
using namespace std;
main ()
{
int a, b, c;
cin >> a>>b>>c;
int wynik= a+b+c;
if (wynik>2*a+2*b)
wynik=2*a+2*b;
if (wynik>2*c+2*b)
wynik=2*c+2*b;
if (wynik>2*a+2*c)
wynik=2*a+2*c;
cout <<wynik;
}