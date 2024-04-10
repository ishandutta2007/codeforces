#include <iostream>

using namespace std;

int main()
{char c;
    int ok=0;

cin>>c;
    while(!cin.eof())
    {
int a=c-'0';
if(a<5)
    cout<<a, ok=1;
if(5<=a && a<=8)
    cout<<9-a, ok=1;
if(a==9)
    {if(ok==0)
    cout<<9, ok=1;
else
    cout<<0;
}

cin>>c;
}

 return 0;
}