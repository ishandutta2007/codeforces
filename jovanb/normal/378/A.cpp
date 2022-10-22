#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);


    int a,b,mog1=0,mog2=0,mog3=0,raz1,raz2,i,j;
    cin>>a>>b;
    for(i=1;i<=6;i++){
        raz1=abs(i-a);
        raz2=abs(i-b);
        if(raz1<raz2)mog1++;
        else if(raz1==raz2)mog3++;
        else mog2++;
    }
    cout<<mog1<<" "<<mog3<<" "<<mog2;
    return 0;
}