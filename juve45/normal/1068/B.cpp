#include <iostream>

using namespace std;
long long x, nrdiv, divi, p;
int main()
{
    cin>>x;
        nrdiv=1;
        divi=2;
        while(divi*divi<=x)
        {
            p=0;
            while(x%divi==0)
            {
                p++;
                x/=divi;
            }
            nrdiv=nrdiv*(p+1);
            divi++;
        }
        if(x>1)
            nrdiv*=2;
        cout<<nrdiv<<'\n';
    return 0;
}