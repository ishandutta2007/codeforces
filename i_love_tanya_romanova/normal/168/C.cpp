#include <iostream>
#include <cmath>
#include <conio.h>
#include <iomanip>
using namespace std;

void main()
{
    cout.precision(5);
    long int f1,n,a,d,f;
    double s,temp,tt=0.0;
    cin >> n >> a >>d;
    long int *t=new long int [n];
    long int *v=new long int [n];
    for(f=0;f<n;f++) cin>>t[f]>>v[f];
    for(f=0;f<n;f++)
    {
        //temp=v[f];
        s=double(v[f])*double(v[f])/(2*double(a));
        if (s>d) 
        {
            temp=sqrt(2*double(d)/a)+t[f];
            if (temp>tt) {cout<<fixed<<setprecision(5)<<temp<<endl;tt=temp;} else cout<<fixed<<setprecision(5)<<tt<<endl;
        }
        else
        {
            temp=sqrt(2*s/a)+t[f]+(d-s)/v[f];
            if (temp>tt) {cout<<fixed<<setprecision(5)<<temp<<endl;tt=temp;} else cout<<fixed<<setprecision(5)<<tt<<endl;
        }
    }
//  system("pause");
}