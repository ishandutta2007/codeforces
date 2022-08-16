#include <bits/stdc++.h>
using namespace std;
int check_pt(int a,int b)
{
    if(a>=0 && a<=7 && b>=0 && b <= 7)
        return 1;
    return 0;
}
int main()
{
    string s;
    cin>>s;
    int x = s[0]-'a',y = s[1]-'1';
    cout<<check_pt(x+1,y)+check_pt(x,y+1)+check_pt(x-1,y)+check_pt(x,y-1)+check_pt(x+1,y+1) + check_pt(x+1,y-1) + check_pt(x-1,y+1) + check_pt(x-1,y-1);
}