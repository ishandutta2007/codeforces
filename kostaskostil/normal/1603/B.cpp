#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

typedef long long ll;
#define int ll

using namespace std;

int ans(int x, int y)
{ /// n%x = y%n
    if (x > y)
        return x+y;
    if (3*x > y)
        return (x+y)/2;
    if (y%x == 0)
        return x;

    {
        for (int i=1; i<=min<int>(x, 5); i++)
            if ((y-i) % x == i)
                return y-i;
    }
    int y2 = (y-2)%x - 2;
    int y3 = (y-3)%x - 3;
    int dx = 2 - y2 / (y3 - y2);

//    cout<<y2<<" "<<y3<<" "<<dx<<"\n";
    if (dx < 0)
        dx += x;
    if ((y - dx) % x == dx)
        return y-dx;

    cout<<"pain\n";
    return -1;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

//    int M = 1000;
//    for (int i=2; i<=M; i+=2)
//        for (int j=2; j<=M; j+=2)
//    {
////        cout<<i<<", "<<j<<": ";
//        int n = ans(i, j);
////        for (int n=1; n<=j; n++)
//            if (n%i != j%n)
//                cout<<i<<" "<<j<<" "<<n<<"\n";
//
////                cout<<n<<", ";
////            else
////                exit(0);
////        cout<<"\n";
//    }
    int _;
    cin>>_;
    while (_--)
    {
        int x, y;
        cin>>x>>y;
        cout<<ans(x, y)<<"\n";
    }
}