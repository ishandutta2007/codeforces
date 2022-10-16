#include <iostream>
#include <iostream>
#include <algorithm>

using namespace std;

int a[5];

int main()
{
    cin>>a[0];
    cin>>a[1];
    cin>>a[2];
    cin>>a[3];

    sort(a, a+4);
    if(a[3] < a[2] + a[1] || a[2] < a[1] + a[0])
    {
        cout<<"TRIANGLE";
        return 0;
    }
    if(a[3] == a[2] + a[1] || a[2] == a[1] + a[0])
    {
        cout<<"SEGMENT";
        return 0;
    }

    cout<<"IMPOSSIBLE";

    return 0;
}