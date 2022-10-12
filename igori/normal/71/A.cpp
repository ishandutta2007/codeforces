#include <iostream>
#include <string>

using namespace std;

int main()
{
    string m[100];
    int n;
    cin>>n;
    int s;
    for(int i=0;i<n;i++)
       cin>>m[i];
    for(int i=0; i<n;i++)
    {
        s=m[i].size();
        if(s<11)
            cout<<m[i];
        else
        {
            cout<<m[i][0]<<s-2<<m[i][s-1];
        }
        cout<<endl;
    }

}