#include <iostream>

using namespace std;

int main()
{
    int na,nb,k,m,a[100005],b[100005];
    cin>>na>>nb;
    cin>>k>>m;
    for (int i=0;i<na;i++){
        cin>>a[i];
    }
    for (int i=0;i<nb;i++){
        cin>>b[i];
    }

   if (a[k-1]<b[nb-m]) cout<<"YES";
    else cout<<"NO";
    return 0;
}