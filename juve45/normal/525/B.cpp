#include <iostream>
#include <cstring>
using namespace std;

int n, m;
char s[200009];
int is[200009];

int main()
{
cin>>s;

int lg=strlen(s);
for(int i=0;i<lg+1;i++)
    is[n]=1;
cin>>m;

for(int i=1;i<=m;i++)
{
    cin>>n;
    n--;
    is[n]++;
    is[lg-n]++;
}
 /*   n--;
    char aux=s[n];
    s[n]=s[lg-n-1];
    s[lg-n-1]=aux;
}*/
int sum=0;
for(int i=0;i<lg;i++)
{
    sum+=is[i];
    if(sum%2==1)
cout<<s[i];
else cout<<s[lg-i-1];
}
    return 0;
}