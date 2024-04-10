#include <iostream>

using namespace std;

int main()
{
    int l[5][5];
    int ik,jk;
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            cin>>l[i][j];

        if(l[i][j]==1)
        {
            ik=i;
            jk=j;
        }
        }
    }
    int m=0;
    if((ik==0)||(ik==4))
        m=m+2;
    if((ik==1)||(ik==3))
        m=m+1;
    if((jk==0)||(jk==4))
        m=m+2;
    if((jk==1)||(jk==3))
        m=m+1;
    cout<<m;



}