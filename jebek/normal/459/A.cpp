#include <iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int x,y,x2,y2;


int main()
{
    cin>>x>>y>>x2>>y2;
    if(x==x2)
    {
        cout<<x+y-y2<<" "<<y<<" "<<x+y-y2<<" "<<y2<<endl;
    }
    else if(y==y2)
    {
        cout<<x<<" "<<y+x-x2<<" "<<x2<<" "<<y+x-x2<<endl;
    }
    else
    {
        if(abs(x2-x)!=abs(y2-y))
        {
            cout<<-1<<endl;
            return 0;
        }
        cout<<x<<" "<<y2<<" "<<x2<<" "<<y<<endl;
    }
}