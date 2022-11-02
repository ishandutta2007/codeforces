#include<bits/stdc++.h>
using namespace std;
char board[10][10];
int main()
{
    int a,b;
    cin>>a>>b;
    for(int x=1;x<=a;x++)
        for(int y=1;y<=b;y++)
            cin>>board[x][y];
    int licz = 0;
    if(board[1][1] != '*')
    {
        board[1][1] = '*';
        licz--;
    }
    if(board[a][b] != '*')
    {
        board[a][b] = '*';
        licz--;
    }
    auto p = make_pair(1,1);
    if(board[1][1] == '*')
        licz++;
    while(p != make_pair(a,b))
    {
        pair<int,int> p2;
        int odl = 1e9;
        for(int x=p.first;x<=a;x++)
            for(int y=p.second;y<=b;y++)
            {
                if(x == p.first && y == p.second)
                    continue;
                if(board[x][y] == '*' && x - p.second + y - p.first < odl)
                {
                    odl = x - p.second + y - p.first;
                    p2 = make_pair(x,y);
                }
            }
        licz ++;
        p = p2;
       // cout<<p.first<<" "<<p.second<<'\n';
    }
    cout<<licz;
    return 0;
}