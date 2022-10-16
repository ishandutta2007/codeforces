#include <cstring>
#include <iostream>

using namespace std;

int nr[300], lg;
char s[200009];

int main()
{
cin>>s;

int lg=strlen(s);
int n=lg;
for(int i=0;i<n;i++)
{
    nr[s[i]]++;
}

for(int i='a', j='z';i!=j;i++)
{
    if(nr[i]%2==0)
        continue;
    while(nr[j]%2==0 && i!=j) j--;
    if(i==j)
        break;
    nr[j]--;
    nr[i]++;
}
int mid=-1;
for(int i='a';i<='z';i++)
{
    
        for(int j=0;j<(nr[i]/2);j++)
            cout<<char(i);
    if(nr[i]%2!=0)
     mid=i;
}
if(mid!=-1)  cout<<char(mid);
//    for(int i=0;i<nr[mid];i++)
  
for(int i='z';i>='a';i--)
{
        for(int j=0;j<(nr[i]/2);j++)
            cout<<char(i);
}
cout<<'\n';
    return 0;
}