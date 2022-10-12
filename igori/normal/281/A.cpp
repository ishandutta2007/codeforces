#include <iostream>
#include <string>

using namespace std;

int main()
{
     string a;
     cin>>a;
     if(a[0]>'Z')
        a[0]=a[0]+'A'-'a';
     cout<<a;

}