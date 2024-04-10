#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
     long long n,w,k,nil=0;
     cin>>k>>n>>w;
     cout<<max((((k+(w*k))*w)/2)-n,nil);
}