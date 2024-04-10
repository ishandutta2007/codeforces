#include <iostream>
#include<string>

using namespace std;

string s1,s="qwertyuiopasdfghjkl;zxcvbnm,./";
char c;

int main()
{
    cin>>c>>s1;
    for(int i=0;i<s1.size();i++)
    {
        for(int j=0;j<s.size();j++)
            if(s1[i]==s[j])
            {
                if(c=='L')
                    s1[i]=s[j+1];
                else
                    s1[i]=s[j-1];
                break;
            }
    }
    cout<<s1<<endl;
}