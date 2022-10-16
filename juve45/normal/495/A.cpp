#include <iostream>
#include <algorithm>

using namespace std;

int v[]={2, 7, 2, 3, 3, 4, 2, 5, 1, 2};

int main()
{
    char a, b;
    cin>>a>>b;
    int x=a-'0';
    int y=b-'0';
    cout<<v[x]*v[y];


    return 0;
}