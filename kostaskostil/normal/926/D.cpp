#include <iostream>
#include <string>
using namespace std;

int main()
{
    int q=0;
    string s,t;
    for (int i=1; i<=3; i++)
        {
            cin>>s>>t;
            if (q==1)
            cout<<s<<"\n"<<t<<"\n";
            else
            {
                if (s[3]=='.')
                {
                    s[3]='P';
                    q=1;
                }
                else 
                if (s[4]=='.')
                {
                    s[4]='P';
                    q=1;
                }
                else
                if (t[3]=='.')
                {
                    t[3]='P';
                    q=1;
                }
                else 
                if (t[4]=='.')
                {
                    t[4]='P';
                    q=1;
                }
                else 
                if (s[1]=='.')
                {
                    s[1]='P';
                    q=1;
                }
                else 
                if (s[0]=='.')
                {
                    s[0]='P';
                    q=1;
                }
                else 
                if (s[6]=='.')
                {
                    s[6]='P';
                    q=1;
                }
                else 
                if (s[7]=='.')
                {
                    s[7]='P';
                    q=1;
                }
                else
                if (t[0]=='.')
                {
                    t[0]='P';
                    q=1;
                }
                else 
                if (t[1]=='.')
                {
                    t[1]='P';
                    q=1;
                }
                else
                if (t[6]=='.')
                {
                    t[6]='P';
                    q=1;
                }
                else 
                if (t[7]=='.')
                {
                    t[7]='P';
                    q=1;
                }
                cout<<s<<"\n"<<t<<"\n";
            }
        }
        
}