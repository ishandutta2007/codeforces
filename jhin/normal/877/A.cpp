#include <iostream>

using namespace std;
string x,y;int i,c;
void checkD(char s){x="";if(s=='D')for(int j=i;j<y.size()&&j<i+5;j++)x+=y[j];if(x=="Danil")c++;}
void checkO(char s){x="";if(s=='O')for(int j=i;j<y.size()&&j<i+4;j++)x+=y[j];if(x=="Olya")c++;}
void checkS(char s){x="";if(s=='S')for(int j=i;j<y.size()&&j<i+5;j++)x+=y[j];if(x=="Slava")c++;}
void checkA(char s){x="";if(s=='A')for(int j=i;j<y.size()&&j<i+3;j++)x+=y[j];if(x=="Ann")c++;}
void checkN(char s){x="";if(s=='N')for(int j=i;j<y.size()&&j<i+6;j++)x+=y[j];if(x=="Nikita")c++;}
int main()
{
    cin>>y;
    for(i=0;i<y.size();i++)
    {
        checkD(y[i]);checkO(y[i]);checkS(y[i]);checkA(y[i]);checkN(y[i]);
    }
    if(c==1)cout<<"YES";else cout<<"NO";
    return 0;
}