#include <iostream>
#include <vector>
#include <cstring>

#define dmax 105

using namespace std;

char a[dmax][dmax];
int n, m;


bool check(int k)
{
    for(int i=1;i<n;i++)
    {
        int ii=0;

        //for(int ii=0;ii<k;ii++)
        //if(a[i][ii]<a[i+1][ii])
          //  return true;

        while(a[i][ii]==a[i+1][ii] && ii<k)
            ii++;

        if(a[i][ii]>a[i+1][ii])
            return false;
    }

    return true;


}

void pop(int k)
{
    for(int i=1;i<=n;i++)
        for(int j=k;j<m;j++)
            a[i][j]=a[i][j+1];
    m--;
}

int main()
{
cin>>n>>m;
int g=0;

for(int i=1;i<=n;i++)
cin>>a[i];

for(int i=0;i<m;i++)
{
    if(!check(i))
        g++, pop(i), i--;

}

cout<<g<<'\n';
    return 0;
}