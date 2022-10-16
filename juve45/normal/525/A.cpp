#include <iostream>

using namespace std;

int n;
char a, b;
int d[30];

int main()
{
cin>>n;
int k=0;
for(int i=1;i<n;i++)
{
    cin>>a>>b;
    int g=a-'a';
    int f=b-'A';

    if(f==g) continue;
    else
    {
    d[a-'a']++;
    if(d[b-'A']==0)
    k++;
    else d[b-'A']--;
    }
}
cout<<k;

    return 0;
}