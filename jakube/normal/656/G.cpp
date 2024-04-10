#include <iostream>
using namespace std;
int main()
{
    int F,I,T,C=0,i,j,t;
    cin>>F>>I>>T;
    string v[10];
    for(i=0;i<F;i++)cin>>v[i];
    for(i=0;i<I;i++){t = 0;for (j=0;j<F;j++)t+=v[j][i]=='Y';C += t >= T;}
    cout<<C;
}//kitten