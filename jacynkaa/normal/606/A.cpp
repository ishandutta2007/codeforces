#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
main ()
{ int x=0;
vector <int> costam (3);
for(int i=0; i<3; i++)
cin >>costam[i];
for(int i=0; i<3; i++)
{int a;
cin >>a;
costam[i]=costam[i]-a;
if (costam[i]>0)
costam[i]=costam[i]/2;
x=costam[i]+x;
}
if (x>=0)
cout <<"Yes";
else
cout<< "No";

}