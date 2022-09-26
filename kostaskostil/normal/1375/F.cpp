#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
#define int ll

int mx(int a, int b, int c)
{
    return max(max(a, b), c);
}
int mn(int a, int b, int c)
{
    return min(min(a, b), c);
}
int ser(int a, int b, int c)
{
    return a+b+c-mx(a, b, c)-mn(a, b, c);
}

bool iff(int a, int b, int c)
{
    int d=abs(mx(a, b, c)-ser(a, b, c)-ser(a, b, c)+mn(a, b, c));
    if (2*ser(a, b, c)<mx(a, b, c)+mn(a, b, c))
        return false;
    return ser(a, b, c)+d <= mx(a, b, c);
}

void try1(int& a, int& b, int& c)
{
    int d=abs(mx(a, b, c)-ser(a, b, c)-ser(a, b, c)+mn(a, b, c));
    if (d==0)
        return;
    cout<<d<<endl;
    int x;
    cin>>x;
    if (x==1) a+=d;
    if (x==2) b+=d;
    if (x==3) c+=d;

    d=abs(mx(a, b, c)-ser(a, b, c)-ser(a, b, c)+mn(a, b, c));
    if (d==0)
        return;
    cout<<d<<endl;
    cin>>x;
    if (x==1) a+=d;
    if (x==2) b+=d;
    if (x==3) c+=d;
}

void don(int a, int b, int c)
{
    int y=mx(a, b, c)-ser(a, b, c);
    cout<<y<<endl;
    int x;
    cin>>x;
    if (a==mx(a, b, c)) a+=y;
    if (b==mx(a, b, c)) b+=y;
    if (c==mx(a, b, c)) c+=y;
    cout<<5*y<<endl;
    cin>>x;
    if (x==1)
    {
        if ((a<b) and (a<c))
            cout<<2*y<<endl;
        else cout<<3*y<<endl;
    }
    if (x==2)
    {
        if ((b<a) and (b<c))
            cout<<2*y<<endl;
        else cout<<3*y<<endl;
    }
    if (x==3)
    {
        if ((c<b) and (c<a))
            cout<<2*y<<endl;
        else cout<<3*y<<endl;
    }
    exit(0);
}


main()
{ 

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));

    int a, b, c;
    cin>>a>>b>>c;
    cout<<"First "<<endl;
    unsigned long long d=0;
    while (iff(a, b, c)==false)
    {
//        int d=(rand()<<15)+rand();
        d=(2*d)+(rand()%2);
        d%=(1000000000000);
        d++;
        cout<<d<<endl;
    int x;
    cin>>x;
    if (x==1) a+=d;
    if (x==2) b+=d;
    if (x==3) c+=d;

//    cout<<a<<" "<<b<<" "<<c<<endl;
    }
    try1(a, b, c);
    don(a, b, c);
}