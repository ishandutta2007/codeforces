#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    string s;
    int a,b;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>s>>a>>b;
        if((a<b)&&(a>=2400))
        {
            cout<<"YES";;
            return 0;
        }
    }
    cout<<"NO";
}