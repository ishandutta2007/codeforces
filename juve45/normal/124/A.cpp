#include <iostream>
#include <vector>

using namespace std;

int a, b, n;

int main()
{
    //n=0;
    cin>>n;
    cin>>a>>b;

    n=n-a;
    cout<<min(n, b+1);

    return 0;
}