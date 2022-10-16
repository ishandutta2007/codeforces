#include <iostream>

using namespace std;
string s1, s2;
int main()
{
cin>>s2>>s1;


int last=s2.size()-1;
while(s2[last]=='z')
    s2[last]='a', last--;
s2[last]++;
if(s2!=s1)
cout<<s2;
else cout<<"No such string";


    return 0;
}