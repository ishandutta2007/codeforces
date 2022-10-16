#include <iostream>

using namespace std;

long long n, m, b1, b2, a1, a2, c;


int main()
{
cin>>n>>b1;
for(int i=1;i<=n;i++)
        cin>>c,
        a1=a1*b1+c;
        
cin>>n>>b1;
for(int i=1;i<=n;i++)
        cin>>c,
        a2=a2*b1+c;
        
        if(a1<a2)
            cout<<"<\n";
        else if(a1==a2)
            cout<<"=\n";
        else cout<<">\n";
        
        return 0;
}