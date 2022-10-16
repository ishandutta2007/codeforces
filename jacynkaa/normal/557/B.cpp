
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
main ()

{
    long long int n, w;
cin >> n>>w;
vector <long long int> costam (2*n);
for (int i=0; i<2*n; i++)
cin >> costam[i];
sort (costam.begin(), costam.end());
long long int z=costam[0];
long long  int k=costam[n];
/*for (int i=0; i<2*n; i++)
cout << costam[i]<<endl; */
if (z*2>k)
{if (k*15*n>=w*10)
cout <<w;
else
{ w=k*15*n;
if (w%10==0)
cout <<w/10;
else cout << w/10 <<"."<<w%10;

}
}
else
{if (3*z*n>=w)
cout<<w;
else
cout <<3*z*n;




}
}