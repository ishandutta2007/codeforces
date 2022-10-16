#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

main ()
{
    string A;
    cin >> A;
    int dlugosc1=0;
    int dlugosc0=0;

    for (int i=0; i<A.length(); i++)
    {
        if (A[i]=='0')
        {
            dlugosc0++;
            dlugosc1=0;
        }
        else
        {
            dlugosc1++;
            dlugosc0=0;
        }
if (dlugosc1==7||dlugosc0==7)
{cout << "YES"<<endl;
return 0;}

    }
cout << "NO" <<endl;


}