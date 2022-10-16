#include <bits/stdc++.h>

using namespace std;

int ans1=10;
int ans2=10;
char a[11][11];
int main()
{
    
    for(int i=1;i<=8;i++)
    for(int j=1;j<=8;j++)
        cin>>a[i][j];
        int ok=0;
    for(int j=1;j<=8;j++)
    {
        ok=0;
        for(int i=1;i<=8;i++)
        {
            if(a[i][j]=='B' && ok == 0)
                ok=i;
            if(a[i][j]=='W' && ok != 0)
            {
                for(int k=ok;k<=i;k++) a[k][j]='.';
                break;
            }
        }
    }
      /*  

    for(int i=1;i<=8;i++)
    {
        for(int j=1;j<=8;j++)
           cout << a[i][j];
       cout << '\n';
    }
    */
    for(int i=1;i<=8;i++)
    for(int j=1;j<=8;j++)
    {
        if(a[i][j]=='W')
            ans1=min(i-1, ans1);
        if(a[i][j]=='B')
            ans2=min(8-i, ans2);
    }
//    cout << ans1 << ' ' << ans2 << '\n';
    if(ans1<=ans2)
        cout<<"A\n";
    else cout<<"B\n";
        return 0;
}