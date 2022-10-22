#include <bits/stdc++.h>

using namespace std;

int main()
{
 int n;
 cin>>n;
 if(n%7==6){cout<<(floor(n/7)*2)+1<<" ";}
 else
    {cout<<(floor(n/7)*2)<<" ";}
    if(n%7==1){cout<<(((n-1)/7)*2)+1;}
    else{cout<<ceil(n/7.0)*2;}


 return 0;
}