#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a[8][8]={0};
    string s[8];
    int ans=0;

    for(int i=2; i<6; i++)
    {
        cin>>s[i];
        for(int j=2; j<6; j++)
        {
            if(s[i][j-2]=='.')
                a[i][j]=0;
            if(s[i][j-2]=='x')
                a[i][j]=1;
            if(s[i][j-2]=='o')
                a[i][j]=-1;
        }
    }

    for (int i=2; i<6; i++)
      {for (int j=2; j<6; j++) {
          if(a[i][j]==0)
          {
              a[i][j]==1;
              if((a[i-1][j]==1)&&(a[i-2][j]==1))
              {ans=1; goto done;}
              if((a[i-1][j-1]==1)&&(a[i-2][j-2]==1))
              {ans=1; goto done;}
              if((a[i][j-1]==1)&&(a[i][j-2]==1))
              {ans=1; goto done;}
              if((a[i+1][j-1]==1)&&(a[i+2][j-2]==1))
              {ans=1; goto done;}
              if((a[i+1][j]==1)&&(a[i+2][j]==1))
              {ans=1; goto done;}
              if((a[i+1][j+1]==1)&&(a[i+2][j+2]==1))
              {ans=1; goto done;}
              if((a[i][j+1]==1)&&(a[i][j+2]==1))
              {ans=1; goto done;}
              if((a[i-1][j+1]==1)&&(a[i-2][j+2]==1))
              {ans=1; goto done;}
              if((a[i-1][j]==1)&&(a[i+1][j]==1))
              {ans=1; goto done;}
              if((a[i-1][j-1]==1)&&(a[i+1][j+1]==1))
              {ans=1; goto done;}
              if((a[i][j-1]==1)&&(a[i][j+1]==1))
              {ans=1; goto done;}
              if((a[i-1][j+1]==1)&&(a[i+1][j-1]==1))
              {ans=1; goto done;}
              a[i][j]==0;
          }

        }
      }

    done:
    if(ans==1)
    {
        cout<<"YES";
    }
    else
        cout<<"NO";

}