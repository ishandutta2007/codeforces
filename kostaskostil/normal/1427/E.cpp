#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long ll;
#define int ll

stringstream ss;

bool xoring=0;

int n;
unordered_set<int> st;
vector<int> v;

void konets()
{
    if (st.find(1)==st.end())
        cout<<"=((\n",exit(0);

    cout<<n-1<<"\n";
    cout<<ss.str();

//    cout<<n<<"\n";
//    cout<<xoring;
    exit(0);
}

void pl(int r1, int r2)
{
    if(st.find(r1)==st.end())
        cout<<r1<<" =(\n", konets();
    if(st.find(r2)==st.end())
        cout<<r2<<" =(\n", konets();
//    if (r1+r2<0)
//        cout<<r1<<"+"<<r2<<"\n",exit(0);
//    if (r1+r2 < 1e7)
        if (st.find(r1+r2)==st.end())
        {
            v.pb(r1+r2);
            st.insert(r1+r2);
            ss<<r1<<" + "<<r2<<"\n";
            n++;
        }
}

void xr(int r1, int r2)
{
    if(st.find(r1)==st.end())
        cout<<r1<<" =(\n", konets();
    if(st.find(r2)==st.end())
        cout<<r2<<" =(\n", konets();
//    if ((r1^r2)<0)
//        cout<<r1<<"^"<<r2<<"\n",exit(0);
//    if (r1==r2)
//        return;
//    if ((r1^r2) < 1e7)
        if (st.find(r1^r2)==st.end())
        {
            v.pb(r1^r2);
            st.insert(r1^r2);
            ss<<r1<<" ^ "<<r2<<"\n";
            n++;
            if ((r1^r2)==1)
                konets();
        }
}

void oper()
{
//    cout<<n<<" "<<v.size()<<" "<<v.back()<<endl;
    int r1=v[rand()%n];
    int r2=v[rand()%n];

    if (rand()%5==0)
        xr(r1, r2);
    else
        pl(r1, r2);
}

bool fb(int x, int y)
{
    if (x<y)
        swap(x, y);
    return ((x^y) < y);
}

void bitix(int x, int c)
{
    int dz=x;
    while (dz%2==0)
        dz/=2;

    int t=x;
    for (int i=1; i<c; i++)
        pl(t, t), t*=2;
    if ((dz/2) % 2 == 1)
    {
        pl(t, x);
        xr(t+x, x);
        t=(t+x)^x;
    }
    pl(t, x);
    xr(x, t);
    xr(x^t, x+t);
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    srand(time(0));
    int x;
    cin>>x;
//    x=(1ll<<20)-3;
    n=1;
    st.insert(x);
    v.pb(x);

//    while ((clock()*1.0/CLOCKS_PER_SEC < 1.0) and (n < 50000))
//        oper();
//    xoring=true;
//    vector<int> bas;
//    for (int i_=0; i_<n; i_++)
//    {
//        int x=v[i_];
//        for (int y:bas)
//            if (fb(x, y))
//            {
//                xr(x, y);
//                x^=y;
//            }
//        if (x>0)
//        {
//            bas.pb(x);
//            sort(bas.begin(), bas.end());
//            reverse(bas.begin(), bas.end());
//        }
//    }
//    cout<<n<<"\n";
//    for (int i:bas)
//        cout<<i<<"\n";
//    cout<<"=(\n";

    int t=x;
    int c=0;
    while (t)
        c++, t/=2;
    t=x;
    for (int i=1; i<=c; i++)
        bitix(t, c), t*=2;

//    for (int i=c; i<2*c; i++)
//        cout<<(st.find(1ll<<i)!=st.end())<<"\n";

    for (int i=c-1; i>=0; i--)
    {
        t=x;
        for (int j=1; j<=i; j++)
            pl(t, t), t*=2;
        for (int j=2*c-1; j>i; j--)
            if (t & (1ll<<j))
                xr(t, (1ll<<j)), t^=(1ll<<j);
    }

//    konets();
}