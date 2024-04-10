#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n=0;
    cin>>n;
    string a;
    cin>>a;
    int go=2;

    int i=0;
    string s="";

    while(i<n)
    {

        if((a[i]=='o')&&(a[i+1]=='g')&&(a[i+2]=='o'))
        {
            s=s+"***";
            i=i+3;
            go=0;

            while((a[i]=='g')&&(a[i+1]=='o'))
            {
                i=i+2;
                go=1;
            }
        }
        else
            go=2;



        if(go==2)
          {i++;s=s+a[i-1];}



    }
    cout<<s;

}