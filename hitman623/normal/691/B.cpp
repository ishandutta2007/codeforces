#include <bits/stdc++.h>

using namespace std;

int main()
{
   char a[19][3]={{'A','A'},{'b','d'},{'d','b'},{'H','H'},{'I','I'},{'M','M'},{'O','O'},{'o','o'},{'p','q'},{'q','p'},{'T','T'},{'U','U'},{'V','V'},{'v','v'},{'W','W'},{'w','w'},{'X','X'},{'x','x'},{'Y','Y'}};
    char b[1001];
    cin>>b;
    int i,f=1,j,m=strlen(b);
    for(i=0;i<(m+1)/2;++i)
    {
        for(j=0;j<19;j++)
          if(b[i]==a[j][0])
        {
            if(b[m-1-i]!=a[j][1]) {f=0;}
            break;
        }
        if(f==0 || j==19) {f=0;break;}
    }
    if(f==1) cout<<"TAK";
    else cout<<"NIE";
    return 0;
}