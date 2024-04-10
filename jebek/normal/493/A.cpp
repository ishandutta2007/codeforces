#include <iostream>
#include<algorithm>
#include<string>

using namespace std;

int n,a,b,k;
char c1,c2;
string s[2];
bool mark1[2][200],mark2[2][200];

int main()
{
    cin>>s[0]>>s[1];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>c1>>b>>c2;
        if(c1=='h')
            k=0;
        else
            k=1;
        if(c2=='r' || mark1[k][b])
        {
            if(!mark2[k][b])
            {
                cout<<s[k]<<" "<<b<<" "<<a<<endl;
                mark2[k][b]=true;
            }
        }
        else if(c2=='y')
            mark1[k][b]=true;
    }
}