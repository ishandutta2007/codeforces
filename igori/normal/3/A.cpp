#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
     string a;
     string b;
     cin>>a>>b;
     int k;
     int a1=a[0]-'a',b1=a[1]-'0'-1,a2=b[0]-'a',b2=b[1]-'0'-1;

     k=max(abs(a1-a2), abs(b1-b2));
     cout<<k<<endl;


     for(int i=0; i<k; i++)
     {
         if((a1>a2) && (b1>b2))
            {cout<<"LD"<<endl; a1--; b1--;}
        if((a1>a2) && (b1==b2))
            {cout<<"L"<<endl; a1--; }
        if((a1>a2) && (b1<b2))
            {cout<<"LU"<<endl; a1--; b1++;}
        if((a1==a2) && (b1>b2))
            {cout<<"D"<<endl; b1--;}

        if((a1==a2) && (b1<b2))
            {cout<<"U"<<endl;  b1++;}
        if((a1<a2) && (b1>b2))
            {cout<<"RD"<<endl; a1++; b1--;}
        if((a1<a2) && (b1==b2))
            {cout<<"R"<<endl; a1++; }
        if((a1<a2) && (b1<b2))
            {cout<<"RU"<<endl; a1++; b1++;}
     }

}