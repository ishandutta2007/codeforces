#include <iostream>
#include <string>
using namespace std;

int main()
{
    string c;
    cin>>c;
    int t=0; int h=c.size();
    for(int i=0; i<h; i++)
    {
        if((c[i]=='4')||(c[i]=='7'))
           t++;
    }
    if((t==4)||(t==7))
       cout<<"YES";
    else
        cout<<"NO";

}