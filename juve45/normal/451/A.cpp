#include <iostream>
#include <algorithm>

using namespace std;

int n, m;

int main()
{

    cin>>n>>m;

    if(min(m, n)%2==0)
    {
        cout<<"Malvika";
    }
    else cout<<"Akshat";

    return 0;
}