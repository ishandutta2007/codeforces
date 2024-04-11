#include<cstdio>
#include<algorithm>

using namespace std;

int nww(int a, int b)
{
    return a/__gcd(a,b)*b;
}

int nww3(int a, int b, int c)
{
    a = nww(a,c);
    return a/__gcd(a,b)*b;
}

int main()
{
    int a, b, c, d, n;
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &n);
    int wyn = 0;
    wyn += n/a;
    wyn += n/b;
    wyn += n/c;
    wyn += n/d;
    wyn -= n/(nww(a,b));
    wyn -= n/(nww(a,c));
    wyn -= n/(nww(a,d));
    wyn -= n/(nww(b,c));
    wyn -= n/(nww(b,d));
    wyn -= n/(nww(c,d));
    wyn += n/(nww3(a,b,c));
    wyn += n/(nww3(a,b,d));
    wyn += n/(nww3(a,c,d));
    wyn += n/(nww3(b,c,d));
    wyn -= n/(nww(nww(a,b),nww(c,d)));
    printf("%d", wyn);
    return 0;
}