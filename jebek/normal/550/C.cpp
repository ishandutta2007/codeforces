#include <iostream>

using namespace std;

string s;

void print(int i)
{
    cout<<"YES"<<endl;
    cout<<s[i]<<endl;
}

void print1(int i,int j)
{
    cout<<"YES"<<endl;
    cout<<s[i]<<s[j]<<endl;
}

void print2(int i,int j,int k)
{
    cout<<"YES"<<endl;
    cout<<s[i]<<s[j]<<s[k]<<endl;
}


int main()
{
    cin>>s;
    for(int i=0;i<s.size();i++)
        if(int(s[i]-'0')%8==0)
        {
            print(i);
            return 0;
        }
    for(int i=0;i<s.size();i++)
        for(int j=i+1;j<s.size();j++)
            if((int(s[i]-'0')*10+int(s[j]-'0'))%8==0)
            {
                print1(i,j);
                return 0;
            }
    for(int i=0;i<s.size();i++)
        for(int j=i+1;j<s.size();j++)
            for(int k=j+1;k<s.size();k++)
                if((int(s[i]-'0')*100+int(s[j]-'0')*10+int(s[k]-'0'))%8==0)
                {
                    print2(i,j,k);
                    return 0;
                }
    cout<<"NO"<<endl;
}