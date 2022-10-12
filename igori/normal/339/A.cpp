#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1;
    cin>>s1;
    int n=s1.size();
    string sk;
    int m[4]={0};
    for(int i=0; i<n; i++)
    {
        if(s1[i]=='1')
            m[1]++;
        if(s1[i]=='2')
            m[2]++;
        if(s1[i]=='3')
            m[3]++;
    }
    for(int i=0; i<m[1]; i++)
        sk=sk+"1+";
    for(int i=0; i<m[2]; i++)
        sk=sk+"2+";
    for(int i=0; i<m[3]; i++)
        sk=sk+"3+";
    for(int i=0; i<n; i++)
        cout<<sk[i];

}