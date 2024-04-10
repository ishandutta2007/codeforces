#include <iostream>

using namespace std;

int voidspell(int x, int y)
{
    int i;
    for(i=0;i<y;i++)
    {
      if(x>20)  x = (x - (x%2))/2 + 10;
    }
    return x;
}

int main()
{
    int t,i;
    cin >> t;
    int inp[t][3];
    for(i=0;i<t;i++)
    {
        cin >> inp[i][0] ;
        cin >> inp[i][1] ;
        cin >> inp[i][2] ;
    }

    for(i=0;i<t;i++)
    {
        if( voidspell(inp[i][0],inp[i][1]) > (10*inp[i][2])) cout << "NO" << endl;
        else cout << "YES" << endl;
    }

    return 0;
}