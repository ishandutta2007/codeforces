#include <iostream>

using namespace std;
char a[100];
int main()
{
    int n,i;
    cin>>n;
    cin>>a;
    int l=0,r=0,u=0,d=0;
    for(i=0;i<n;i++){
        if(a[i]=='L')l++;
        else if(a[i]=='R')r++;
        else if(a[i]=='U')u++;
        else if(a[i]=='D')d++;
    }
    cout<<min(l,r)*2+min(u,d)*2;
    return 0;
}