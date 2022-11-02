#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    int wynik=0;
    if(a%2)
        wynik+=16;
    a/=2;
    if(a%2)
        wynik+=2;
    a/=2;
    if(a%2)
        wynik+=8;
    a/=2;
    if(a%2)
        wynik+=4;
    a/=2;
    if(a%2)
        wynik+=1;
    a/=2;
    if(a%2)
        wynik+=32;
    cout<<wynik;
	return 0;
}