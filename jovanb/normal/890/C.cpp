#include <iostream>

using namespace std;
bool num[200005];
int main()
{
    long br=1,i,n,a;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a;
        if(num[a]==true)br++;
        num[a]++;
    }

    cout<<br;
    return 0;
}