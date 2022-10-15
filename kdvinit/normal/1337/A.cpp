#include <iostream>

using namespace std;

int main()
{
    int t,i;
    cin >> t;
    int inp[t][4];
    for(i=0;i<t;i++)
    {
        cin >> inp[i][0] ;
        cin >> inp[i][1] ;
        cin >> inp[i][2] ;
        cin >> inp[i][3] ;
    }

    for(i=0;i<t;i++)
    {
        cout << inp[i][1] <<" " << inp[i][2] << " " << inp[i][2] << endl;
    }

    return 0;
}