#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    int n;
    cin  >> n;

    int x=0;

    string s1 = "X++";
    string s2 = "++X";
    string s3 = "X--";
    string s4 = "--X";

    for(int i=1; i<=n; i++)
    {
        string str;
        cin>>str;

        if(str==s1 || str==s2)
        {
            //x--;
            x++;
        }

        if(str==s3 || str==s4)
        {
            //x++;
            x--;
        }
    }

    cout << x;

    return 0;
}