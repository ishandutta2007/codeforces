#include <iostream>
#include<cstdio>

using namespace std;

int n,a,b,m;
string s;

int main()
{
    cin>>n;
    getline(cin,s);
    for(int i=0;i<n;i++)
    {
        a=0;b=0;
        getline(cin,s);
        m=s.size();
        if(m<5)
        {
            cout<<"OMG>.< I don't know!"<<endl;
            continue;
        }
        if(s[0]=='m' && s[1]=='i' && s[2]=='a' && s[3]=='o' && s[4]== '.')
            b=1;
        m--;
        if(s[m]=='.' && s[m-1]=='a' && s[m-2]=='l' && s[m-3]=='a' && s[m-4]=='l')
            a=1;
        if(a==1 && b==0)
            cout<<"Freda's"<<endl;
        else if(b==1 && a==0)
            cout<<"Rainbow's"<<endl;
        else
            cout<<"OMG>.< I don't know!"<<endl;
    }
}