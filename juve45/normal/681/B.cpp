#include <iostream>

#define A 1234567
#define B 123456
#define C 1234

using namespace std;

int n, m, a, b;
string s;
int main()
{

cin>>n;

    for(int i=0;i*A<=n;i++)
    {
        for(int j=0;j*B+i*A<=n;j++)
        {
            int c=n-(j*B+i*A);
            if(c%C==0)
            {
                cout<<"YES\n";
                return 0;
            }
        }
    }
    cout<<"NO\n";

    return 0;
}