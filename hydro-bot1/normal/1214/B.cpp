// Hydro submission #625cef10fa9408d417feac1c@1650257680511
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int b,g,n;
    cin>>b>>g>>n;
    printf("%d\n",min(b,n)+min(g,n)-n+1);
    return 0;
}