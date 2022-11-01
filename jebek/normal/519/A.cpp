#include <iostream>

using namespace std;

int ans;

int main()
{
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
        {
            char c;
            cin>>c;
            if(isupper(c))
            {
                if(c=='R')
                    ans+=5;
                if(c=='B' || c=='N')
                    ans+=3;
                if(c=='P')
                   ans++;
                if(c=='Q')
                    ans+=9;
            }
            if(islower(c))
            {
                if(c=='r')
                    ans-=5;
                if(c=='b' || c=='n')
                    ans-=3;
                if(c=='p')
                   ans--;
                if(c=='q')
                    ans-=9;
            }
        }
   //cout<<ans<<endl;
    if(ans>0)
        cout<<"White"<<endl;
    else if(ans==0)
        cout<<"Draw"<<endl;
    else
        cout<<"Black"<<endl;
}