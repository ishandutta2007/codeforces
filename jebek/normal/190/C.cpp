#include <iostream>
#include<string>
#include<vector>

using namespace std;

int n;
string s,ans;
vector<int>v;

int main()
{
    cin>>n;
    for(int i=0;i<2*n-1;i++)
    {
        if(!(cin>>s))
        {
            cout<<"Error occurred"<<endl;
            return 0;
        }
        ans+=s;
        if(s=="pair")
        {
            v.push_back(2);
            ans+='<';
        }
        else if(v.size()==0 && i!=2*n-2)
        {
            cout<<"Error occurred"<<endl;
            return 0;
        }
        else if(v.size()==0)
            break;
        else
        {
            if(v.back()==2)
                ans+=',';
            v.back()--;
            while(v.size() && v.back()==0)
            {
                v.pop_back();
                ans+='>';
                if(v.size()==0 && i!=2*n-2)
                {
                  //  cout<<i<<" "<<ans<<endl;
                    cout<<"Error occurred"<<endl;
                    return 0;
                }
                else
                {
                    if(v.back()==2)
                        ans+=',';
                    v.back()--;
                }
            }
        }
    }
    if((cin>>s) || v.size()>0)
    {
        cout<<"Error occurred"<<endl;
        return 0;
    }
    cout<<ans<<endl;
}