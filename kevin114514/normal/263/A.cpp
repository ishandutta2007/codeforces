#include<bits/stdc++.h>
using namespace std;
int main()
{
    int Ans;
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
        {
            int X;
            cin>>X;
            if(X)  
                Ans=abs(2-i)+abs(2-j);
        }
    cout<<Ans<<endl;
    return 0;
}