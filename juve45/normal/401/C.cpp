#include <iostream>

using namespace std;
int x, y;
int main()
{
cin>>x>>y;
    if(x-1 > y)
        cout<<"-1\n";

    else if(2*(x+1)<y)
        cout<<"-1\n";

    else{
            if(x==y+1)cout<<0,x--;

        while(x!=y && x!=0 && y!=0)
        {
            x--;
            y--;
            y--;
            cout<<"110";
        }
        while(x!=0)
            cout<<"10", x--, y--;
        while(y!=0)
            cout<<1, y--;


        }

    return 0;
}