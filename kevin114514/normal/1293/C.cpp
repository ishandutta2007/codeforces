#include<bits/stdc++.h>
using namespace std;
bool OK[2][100100];
int XX;
int main()
{
    int N,Q;
    cin>>N>>Q;
    while(Q--)
    {
        int r,c;
        cin>>r>>c;
        r--;
        int XXXXX=1;
        if(OK[r][c])
            XXXXX=-1;
        r^=1;
        XX+=OK[r][c-1]*XXXXX;
        XX+=OK[r][c]*XXXXX;
        XX+=OK[r][c+1]*XXXXX;
        r^=1;
        OK[r][c]^=1;
        if(XX)
            puts("No");
        else    puts("Yes");
    }
    return 0;
}