#include <iostream>

using namespace std;
int a, b, k, v;
int main()
{

    cin>>k>>a>>b>>v;
k--;
    int f=a-(b/k*(k+1)+((b%k)+1))*v;
    if(f>0) cout<<b/k+1+(f+(v-1))/v;
    else cout<<(a+(k+1)*v-1)/((k+1)*v);
    return 0;
}