#include <iostream>

using namespace std;
char ch[100];
int main()
{
    long long n,i,br1=0,br2=0;
    cin>>n;
    cin>>ch;
    for(i=0;i<n/2;i++){br1+=(ch[i]-'0');if(ch[i]!='4' && ch[i]!='7'){cout<<"NO";return 0;}}
    for(i=n/2;i<n;i++){br2+=(ch[i]-'0');if(ch[i]!='4' && ch[i]!='7'){cout<<"NO";return 0;}}
    if(br1==br2)cout<<"YES";
    else cout<<"NO";
    return 0;
}