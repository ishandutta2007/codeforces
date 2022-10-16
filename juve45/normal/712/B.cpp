#include <iostream>

using namespace std;
string s;
int UD, LR;
int abs(int k)
{
    if(k<0)
        return -k;
    return k;
}

int main()
{
cin>>s;

for(int i=0;i<s.size();i++)
{
    if(s[i]=='L')
        LR++;
    if(s[i]=='R')
        LR--;
    if(s[i]=='U')
        UD++;
    if(s[i]=='D')
        UD--;
}

UD=abs(UD);
LR=abs(LR);

if((UD+LR)%2)
{
    cout<<"-1\n";
    return 0;
}
cout<<(UD+LR)/2;


    return 0;
}