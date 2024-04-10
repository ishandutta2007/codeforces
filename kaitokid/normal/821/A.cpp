#include <iostream>

using namespace std;
int a[55][55];
bool r[55][100004],c[55][100004];
int n;
bool d(int i,int j)
{int x=a[i][j];
   for(int l=0;l<n;l++){if(c[j][x-a[i][l]]){return true;}}

    return false;
}

int main()
{
cin>>n;
for(int i=0;i<n;i++)
{for(int j=0;j<n;j++)
{
  cin>>a[i][j];
  r[i][a[i][j]]=true;
  c[j][a[i][j]]=true;
}


}

for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
        if(a[i][j]!=1&&d(i,j)==false){cout<<"No";return 0;}
    }


}
cout<<"Yes";
    return 0;
}