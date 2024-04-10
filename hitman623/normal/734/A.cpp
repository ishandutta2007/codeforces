#include <iostream>

using namespace std;

int main()
{
    long a,A=0,D=0,i;
    char b[100000];
    cin>>a;
    cin>>b;
    for(i=0;i<a;++i)
     {
       if(b[i]=='A') A++;
       if(b[i]=='D') D++;
     }
     if(A>D) cout<<"Anton";
     else if(A<D) cout<<"Danik";
     else cout<<"Friendship";
    return 0;
}