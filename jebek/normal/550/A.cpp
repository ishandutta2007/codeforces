#include <iostream>

using namespace std;

string s;
bool mark1,mark2;

int main()
{
    cin>>s;
    for(int i=0;i<s.size()-1;i++)
    {
        if(!mark1 && s[i]=='A' && s[i+1]=='B')
            mark1=true,i++;
        else if(mark1 && s[i]=='B' && s[i+1]=='A')
            mark2=true;
    }
    if(mark2)
    {
        cout<< "YES"<<endl;
        return 0;
    }
    mark1=false;
    for(int i=0;i<s.size()-1;i++)
    {
        if(!mark1 && s[i]=='B' && s[i+1]=='A')
            mark1=true,i++;
        else if(mark1 && s[i]=='A' && s[i+1]=='B')
            mark2=true;
    }
    if(mark2)
    {
        cout<< "YES"<<endl;
        return 0;
    }
    cout<<"NO"<<endl;
}