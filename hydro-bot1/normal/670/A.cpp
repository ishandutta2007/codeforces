// Hydro submission #62550be717cd4d0a41764bd1@1649740775316
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    printf("%d %d\n",n/7*2+max(n%7-5,0),n/7*2+min(n%7,2));
    return 0;
}