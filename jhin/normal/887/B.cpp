#include <bits/stdc++.h>

using namespace std;
int a[3][6];int n,q;

bool finder(int x)
{  int f=x%10,s=0;
   if(x>=10)s=(x/10)%10;
   for(int i=0;i<n;i++)
    {
        for(int j=0;j<6;j++)
        {
            if(a[i][j]==f){if(s==0)return true;
            if(s)for(int k=0;k<n;k++){
                    if(k==i)continue;
                    for(int z=0;z<6;z++)
                    if(a[k][z]==s)return true;
                                        }
                           }
        }
        }return false;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)for(int j=0;j<6;j++){cin>>a[i][j];}
    while(++q){if(!finder(q)){cout<<q-1;return 0;}}
    return 0;
}