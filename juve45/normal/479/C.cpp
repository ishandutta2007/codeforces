#include <iostream>
#include <algorithm>
#define dmax 5002
#define x first
#define y second
using namespace std;

int n;
pair <int, int> a[dmax];

int solve()
{

    int zc=a[1].y;
    for(int i=2;i<=n;i++)
    {
        if(zc<=a[i].y)
            zc=a[i].y;
        else zc=a[i].x;
    }
    return zc;

}

int main()
{
cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i].x>>a[i].y;

    sort(a+1, a+n+1);

    cout<<solve()<<'\n';

    return 0;
}