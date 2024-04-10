#include <iostream>
#include<algorithm>
#include<map>
#include<string>

using namespace std;

string s1,s2,s3,s12;
int n;
map<string,bool>mark;
map<string,int>t;

int main()
{
    cin>>n;
    mark["void"]=true;
    for(int i=0;i<n;i++)
    {
        cin>>s1>>s12;
        s2="";
        int p1=0,p2=s12.size()-1;
        while(s12[p1]=='&')
            p1++;
        while(s12[p2]=='*')
            p2--;
        for(int i=p1;i<=p2;i++)
            s2+=s12[i];
        if(s1.size()==7)
        {
            cin>>s3;
            t[s3]=t[s2]+(s12.size())-(p2+1+p1);
            if(!mark[s2] || t[s3]<0)
                mark[s3]=false;
            else
                mark[s3]=true;
        }
        else
        {
            if(!mark[s2] || t[s2]+(s12.size())<(p2+1+p1))
            {
                cout<<"errtype"<<endl;
                continue;
            }
          //  cout<<t[s2]+(s12.size())<<" "<<(p2+1+p1)<<endl;
            cout<<"void";
            for(int j=0;j<t[s2]+(s12.size())-(p2+1+p1);j++)
                cout<<"*";
            cout<<endl;
        }
    }
}